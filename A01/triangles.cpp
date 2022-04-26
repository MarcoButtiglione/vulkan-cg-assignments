/**************
					 Function Triangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)

					 draws a triangle connecting points (x1,y1)  (x2, y2) and (x3, y3), colored with the (r,g,b) specified color.
					 vertex are expressed in Normalized screen coordinates, (i.e. in range [-1,+1]), following the Vulkan convention.
					 The red, green and blue (r,g,b) values are in the range [0,1].

					 Using function Triangle(...) try to draw a children house, similar to the one below.

					 First remove the two function below (given only as an example), and replace them with your own.
					 Since it is a C program, you can use for loops if you think it can be helpful in your drawing.
					 The for() command below that draws a sun like shape in exact center of the screen near the top,
					 is an example on how you can use it: please remove it, and replace it with your own code.
					 It is not necessery to use a for loop if you do not really need it: it has been put here only as
					 an example to help students not familiar with C++.
***************/


float ground_left_down_corner_x = -1;
float ground_left_down_corner_y = 1;
float ground_width = 2;
float ground_height = 0.19;


float ground_lev = 0.81;

float facade_left_down_corner_x = 0.07;
float facade_left_down_corner_y = ground_lev;
float facade_width = 0.58;
float facade_height = 0.65;

float door_left_down_corner_x = 0.3;
float door_left_down_corner_y = ground_lev;
float door_width = 0.1;
float door_height = 0.3;

float window1_left_down_corner_x = 0.17;
float window1_left_down_corner_y = 0.42;
float window1_width = 0.1;
float window1_height = 0.15;

float window2_left_down_corner_x = 0.45;
float window2_left_down_corner_y = 0.42;
float window2_width = 0.1;
float window2_height = 0.15;


float roof_left_down_corner_x = -0.03;
float roof_left_down_corner_y = ground_lev - facade_height;
float roof_base = 0.75;
float roof_height = 0.61;


Triangle(
	roof_left_down_corner_x, roof_left_down_corner_y,
	roof_left_down_corner_x + roof_base, roof_left_down_corner_y,
	roof_left_down_corner_x + roof_base/2, roof_left_down_corner_y-roof_height,
	1, 0, 0
);	// Draws a red roof



Triangle(
	ground_left_down_corner_x, ground_left_down_corner_y,
	ground_left_down_corner_x, ground_left_down_corner_y - ground_height,
	ground_left_down_corner_x + ground_width, ground_left_down_corner_y - ground_height,
	0, 1, 0
);	// Draws a green ground

Triangle(
	ground_left_down_corner_x + ground_width, ground_left_down_corner_y - ground_height,
	ground_left_down_corner_x + ground_width, ground_left_down_corner_y,
	ground_left_down_corner_x, ground_left_down_corner_y,
	0, 1, 0
);	// Draws a green ground

Triangle(
	facade_left_down_corner_x, facade_left_down_corner_y,
	facade_left_down_corner_x, facade_left_down_corner_y - facade_height,
	facade_left_down_corner_x + facade_width, facade_left_down_corner_y - facade_height,
	0, 0, 1
);	// Draws a blue facade

Triangle(
	facade_left_down_corner_x + facade_width, facade_left_down_corner_y - facade_height,
	facade_left_down_corner_x + facade_width, facade_left_down_corner_y,
	facade_left_down_corner_x, facade_left_down_corner_y,
	0, 0, 1
);	// Draws a blue facade

Triangle(
	door_left_down_corner_x, door_left_down_corner_y,
	door_left_down_corner_x, door_left_down_corner_y - door_height,
	door_left_down_corner_x + door_width, door_left_down_corner_y - door_height,
	1, 1, 0
);	// Draws a yellow door
Triangle(
	door_left_down_corner_x + door_width, door_left_down_corner_y - door_height,
	door_left_down_corner_x + door_width, door_left_down_corner_y,
	door_left_down_corner_x, door_left_down_corner_y,
	1, 1, 0
);	// Draws a yellow door

Triangle(
	window1_left_down_corner_x, window1_left_down_corner_y,
	window1_left_down_corner_x, window1_left_down_corner_y - window1_height,
	window1_left_down_corner_x + window1_width, window1_left_down_corner_y - window1_height,
	1, 1, 0
);	// Draws a yellow window 1
Triangle(
	window1_left_down_corner_x + window1_width, window1_left_down_corner_y - window1_height,
	window1_left_down_corner_x + window1_width, window1_left_down_corner_y,
	window1_left_down_corner_x, window1_left_down_corner_y,
	1, 1, 0
);	// Draws a yellow window 1


Triangle(
	window2_left_down_corner_x, window2_left_down_corner_y,
	window2_left_down_corner_x, window2_left_down_corner_y - window2_height,
	window2_left_down_corner_x + window2_width, window2_left_down_corner_y - window2_height,
	1, 1, 0
);	// Draws a yellow window 2
Triangle(
	window2_left_down_corner_x + window2_width, window2_left_down_corner_y - window2_height,
	window2_left_down_corner_x + window2_width, window2_left_down_corner_y,
	window2_left_down_corner_x, window2_left_down_corner_y,
	1, 1, 0
);	// Draws a yellow window 2

//SUN
int sun_segments = 64;
float sun_center_x = 0.65;
float sun_center_y = -0.65;
float sun_radius = 0.1;

for (int i = 0; i < sun_segments; i++) {
	Triangle(
		sun_center_x + sun_radius * cos(6.28 / sun_segments * (i - 0.5)), sun_center_y + sun_radius * sin(6.28 / sun_segments * (i - 0.5)),
		sun_center_x, sun_center_y,
		sun_center_x + sun_radius * cos(6.28 / sun_segments * (i + 0.5)), sun_center_y + sun_radius * sin(6.28 / sun_segments * (i + 0.5)),
		1, 0.2, 0);
}

//Orange flower
int o_flower_segments = 64;
float o_flower_center_x = -0.32;
float o_flower_center_y = 0.68;
float o_flower_radius = 0.07;

for (int i = 0; i < o_flower_segments; i++) {
	Triangle(
		o_flower_center_x + o_flower_radius * cos(6.28 / o_flower_segments * (i - 0.5)), o_flower_center_y + o_flower_radius * sin(6.28 / o_flower_segments * (i - 0.5)),
		o_flower_center_x, o_flower_center_y,
		o_flower_center_x + o_flower_radius * cos(6.28 / o_flower_segments * (i + 0.5)), o_flower_center_y + o_flower_radius * sin(6.28 / o_flower_segments * (i + 0.5)),
		1, 0.2, 0);
}
//Pink flower
int p_flower_segments = 64;
float p_flower_center_x = -0.12;
float p_flower_center_y = 0.68;
float p_flower_radius = 0.07;

for (int i = 0; i < o_flower_segments; i++) {
	Triangle(
		p_flower_center_x + p_flower_radius * cos(6.28 / p_flower_segments * (i - 0.5)), p_flower_center_y + p_flower_radius * sin(6.28 / p_flower_segments * (i - 0.5)),
		p_flower_center_x, p_flower_center_y,
		p_flower_center_x + p_flower_radius * cos(6.28 / p_flower_segments * (i + 0.5)), p_flower_center_y + p_flower_radius * sin(6.28 / p_flower_segments * (i + 0.5)),
		1, 0.4, 0.5);
}

/*
int segments = 64;
float center_x = 0;
float center_y = 0;
float radius = 0.2;

for (int i = 0; i < segments; i++) {
	Triangle(
		center_x + radius * cos(6.28 / segments * (i - 0.5)),  center_y + radius * sin(6.28 / segments * (i - 0.5)),
		center_x, center_y,
		center_x + radius * cos(6.28 / segments * (i + 0.5)),  center_y + radius * sin(6.28 / segments * (i + 0.5)),
		1, 0, 0);
}
*/

/*
for (int i = 0; i < segments; i++) {
	Triangle(
		0.00 + 0.05 * cos(6.28 / segments * (i - 0.5)), -0.80 + 0.05 * sin(6.28 / segments * (i - 0.5)),
		0.00 + 0.10 * cos(6.28 / segments * i), -0.80 + 0.10 * sin(6.28 / segments * i),
		0.00 + 0.05 * cos(6.28 / segments * (i + 0.5)), -0.80 + 0.05 * sin(6.28 / segments * (i + 0.5)),
		1, 1, 0);
}
*/


