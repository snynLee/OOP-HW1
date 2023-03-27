#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdlib>
#include <Windows.h>

int main()
{
	char canvas[112 + 1];
	char player[] = "*^>^*";
	int player_pos = 10;
	int direction = 0;
	char enemy[] = "#__-";
	int enemy_pos = 50;
	char bullet[] = "-";
	int bullet_pos = player_pos + 6;
	int count = 0;

	bool is_hit = false;

	while (true)
	{
		//game loop
		for (int k = 0; k < 112; k++)
			canvas[k] = ' ';
		canvas[112] = '\0';
		
		// draw player shape to the canvas
		for (int j = 0; j < strlen(player); j++)
			canvas[player_pos + j] = player[j];

		// canvas enemy shape to the canvas
		for (int j = 0; j < strlen(enemy); j++)
			canvas[enemy_pos + j] = enemy[j];

		// draw bullet shape to the canvas
		for (int j = 0; j < strlen(bullet) && count >= 30 && !is_hit; j++)
		{
			canvas[bullet_pos + j] = bullet[j];
		
		}
		
		//update player position
/*		if (player_pos == 100)
			direction = 1;
		else if (player_pos == 0)
			direction = 0;

		// move player position according to its current direction
		if (direction == 1)
			player_pos--;
		else
			player_pos++;
*/
		// update bullet position
		if (bullet_pos == enemy_pos)
			is_hit = true;

		// move bullet position according to its current direction
		if (!is_hit && count >= 30)
			bullet_pos++;
		// render canvas 
		printf("%s \r", canvas);

		// run every 100 ms
		Sleep(100);
		count++;
	}

	return 0;
}