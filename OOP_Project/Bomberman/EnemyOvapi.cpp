#include <algorithm>
#include <iterator>

#include "EnemyOvapi.h"
#include "queue"
#include "Game.h"
#include "Map.h"

EnemyOvapi::EnemyOvapi (const char *p_filename, int p_x, int p_y, std::string p_tag_obj)
{

	transformObject.speed = 2;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = 32;
	srcRect.h = 32;

	destRect.x = p_x * 2;
	destRect.y = p_y * 2;
	destRect.w = srcRect.w * transformObject.scale;
	destRect.h = srcRect.h * transformObject.scale;
	transformPositionToTiles();

	en_dest_rect = destRect;
	en_src_rect = srcRect;

	setTex(p_filename);
	tag_obj = p_tag_obj;
}
void EnemyOvapi::update ()
{
	if ((destRect.x) % 64 == 0 && (destRect.y) % 64 == 0)//3 and 2  are offsets
	{
		transformPositionToTiles();
//		cout << destRect.x << " " << destRect.y << endl;
	}
	if (coordinates_path.size() == 0)//check if we are in the end of our path, then we should restart it over again
	{
		if ((destRect.x) % 64 == 0 && (destRect.y) % 64 == 0)
		{
			transformPositionToTiles();
		}
		else
//			cout << destRect.x << " " << destRect.y << endl;
		return;
	}
//	for (auto const &p: coordinates_path)
//		cout << "(" << p.first << ", " << p.second << ")" << " ";
//	cout << endl;
	if (coordinates_path[0].first == 0 && coordinates_path[0].second <= 0)//y ==0; x < 0
	{
//		cout << "left: " << destRect.x << endl;

		coordinates_path[0].second += transformObject.speed;
		if (coordinates_path[0].second > 0)//if we did all steps, just erase it TODO:was >=0
		{
			destRect.x -= coordinates_path[0].second;//taking offset into account
			coordinates_path.erase(coordinates_path.begin());
		}
		else
			destRect.x -= transformObject.speed;
		en_dest_rect.x = destRect.x;

	}
	else if (coordinates_path[0].first == 0 && coordinates_path[0].second >= 0)//y ==0; x > 0
	{
		coordinates_path[0].second -= transformObject.speed;
		if (coordinates_path[0].second < 0)//if we did all steps, just erase it TODO:was >=0
		{
			destRect.x += coordinates_path[0].second;//taking offset into account
			coordinates_path.erase(coordinates_path.begin());
		}
		else
			destRect.x += transformObject.speed;
		en_dest_rect.x = destRect.x;

	}
	else if (coordinates_path[0].first <= 0 && coordinates_path[0].second == 0)//y < 0; x == 0
	{
		coordinates_path[0].first += transformObject.speed;
		if (coordinates_path[0].first > 0)//if we did all steps, just erase it TODO:was >=0
		{
			destRect.y -= coordinates_path[0].first;//TODO: MAYBE ADD STATIC_CAST//taking offset into account
			coordinates_path.erase(coordinates_path.begin());
		}
		else
			destRect.y -= transformObject.speed;
		en_dest_rect.y = destRect.y;
	}

	else if (coordinates_path[0].first >= 0 && coordinates_path[0].second == 0)//y > 0; x == 0
	{
//		cout << "down: " << destRect.y << endl;
		coordinates_path[0].first -= transformObject.speed;
		if (coordinates_path[0].first < 0)//if we did all steps, just erase it TODO:was >=0
		{
			destRect.y += coordinates_path[0].first;//taking offset into account
			coordinates_path.erase(coordinates_path.begin());
		}
		else
			destRect.y += transformObject.speed;
		en_dest_rect.y = destRect.y;

	}

	destRect.w = srcRect.w * transformObject.scale;
	destRect.h = srcRect.h * transformObject.scale;


//	en_dest_rect = destRect;
//	en_src_rect = srcRect;TODO:maybe return it back
}
void EnemyOvapi::draw ()
{
	TextureManager::draw(texture, srcRect, destRect);

}
void EnemyOvapi::init ()
{

}
bool EnemyOvapi::checkCollision (const SDL_Rect &a, const SDL_Rect &b)
{
	return true;
}
void EnemyOvapi::setTex (const char *p_filename)
{
	texture = TextureManager::loadTexture(p_filename);
}
void EnemyOvapi::transformPositionToTiles ()
{

	for (const auto &obj: Game::gameObjects)
	{
		if (obj->tag_obj == "player1")
		{
			pl_src_rect = obj->srcRect;
			pl_dest_rect = obj->destRect;

			int pl_x = static_cast<int>( pl_dest_rect.x / (32 * 2));//- 2
			int pl_y = static_cast<int>( pl_dest_rect.y / (32 * 2));//- 3
			int en_x = static_cast<int>( en_dest_rect.x / (32 * 2));//- 2
			int en_y = static_cast<int>( en_dest_rect.y / (32 * 2));//- 3
			findShortestPath({en_x, en_y}, {pl_x, pl_y});//initiate BFS algorithm
		}
	}
}
void EnemyOvapi::printPath (vector<pair<int, int>> &path)
{
	vector<pair<int, int>> temp_vec;
	int size = path.size() - 1;
	for (int i = 0; i < size; i++)
	{
		int diffY = path[i + 1].first - path[i].first;
		int diffX = path[i + 1].second - path[i].second;
		temp_vec.emplace_back(diffY * 64, diffX * 64);//transforming coordinates to steps we should make to get to our target
//		cout << path[i].first << ":" << path[i].second << endl;

	}
//	cout << path[path.size() - 1].first << " " << path[path.size() - 1].second << endl;
	coordinates_path = temp_vec;


}

bool EnemyOvapi::isNotVisited (const pair<int, int> &to_find, const vector<pair<int, int>> &path)
{
	for (auto const &p: path)
	{
		if (p.first == to_find.first && p.second == to_find.second)
			return false;
	}
	return true;
}

void EnemyOvapi::findShortestPath (const SDL_Rect &en_rect, const SDL_Rect &pl_rect)
{
	pair<int, int> dst{pl_rect.y, pl_rect.x};
	pair<int, int> src{en_rect.y, en_rect.x};
	queue<vector<pair<int, int>>> queue_paths;//queue of all paths
	vector<pair<int, int>> current_path;//current path
	current_path.emplace_back(src);//adding from which position we should go
	queue_paths.push(current_path);
	while (!queue_paths.empty())
	{
		current_path = queue_paths.front();//assigns the value of the top path from our queue
		queue_paths.pop();//removes first element
		pair<int, int> last = current_path[current_path.size() - 1];
		if (last == dst)
		{
			printPath(current_path);
		}
		//========================================================================
		int y_ind = last.first, y_plus_one = last.first + 1, y_minus_one = last.first - 1;
		int x_ind = last.second, x_plus_one = last.second + 1, x_minus_one = last.second - 1;
		//========================================================================

		//Trying to look at the piece above our enemy. We are getting a position of our current path on our 2d array.
		// If its value == 2, then we should consider checking it in the path
		if (Map::map_arr[y_minus_one][x_ind] == 2)//up
		{
			if (isNotVisited({y_minus_one, x_ind}, current_path))//it means that we havent visited it yet
			{
				vector<pair<int, int>> new_path(current_path);
				new_path.emplace_back(y_minus_one, x_ind);
				queue_paths.push(new_path);
			}
		}
		//Trying to look at the piece on the right side of our enemy.
		if (Map::map_arr[y_ind][x_plus_one] == 2)//right
		{
			if (isNotVisited({y_ind, x_plus_one}, current_path))//it means that we havent visited it yet
			{
				vector<pair<int, int>> new_path(current_path);
				new_path.emplace_back(y_ind, x_plus_one);
				queue_paths.push(new_path);
			}
		}
		//Trying to look at the piece underneath our enemy.
		if (Map::map_arr[y_plus_one][x_ind] == 2)//down
		{
			if (isNotVisited({y_plus_one, x_ind}, current_path))//it means that we havent visited it yet
			{
				vector<pair<int, int>> new_path(current_path);
				new_path.emplace_back(y_plus_one, x_ind);
				queue_paths.push(new_path);
			}
		}
		//Trying to look at the piece on the left side of our enemy.
		if (Map::map_arr[y_ind][x_minus_one] == 2)//left
		{
			if (isNotVisited({y_ind, x_minus_one}, current_path))//it means that we havent visited it yet
			{
				vector<pair<int, int>> new_path(current_path);
				new_path.emplace_back(y_ind, x_minus_one);
				queue_paths.push(new_path);
			}
		}


	}


}