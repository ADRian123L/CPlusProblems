#include <stdio.h>

struct color
{ 
    int red;
    int green;
    int blue;
};

struct color make_struct(int red, int green, int blue);
struct color brighter(struct color);

int main(void)
{
    struct color magenta = {255, 0, 255};
    printf("The color codes for magenta: red: %d, green: %d, blue: %d.\n", magenta.red, magenta.green, magenta.blue);
	
    struct color color2;
    printf("Enter the color for red: ");
    scanf("%d", &color2.red);
    printf("Enter the color for green: ");
    scanf("%d", &color2.green);
    printf("Enter the coloer for blue: ");
    scanf("%d", &color2.blue);

    printf("The color codes for color2: red: %d, green: %d, blue: %d.\n", color2.red, color2.green, color2.blue);

    struct color gold = make_struct(255, 215, 0);
    struct color brighter_color = brighter(gold);
    printf("The color codes for bright_color: red: %d, green: %d, blue: %d.\n", brighter_color.red, brighter_color.green, brighter_color.blue);
    return 0;
}

struct color make_struct(int red, int green, int blue)
{
    struct color p;
    // Set the value for red:
    if (red > 255)
	p.red = 255;
    else if (red < 0)
	p.red = 0;
    else
	p.red = red;
     // Set the value for green:
     if (green > 255)
	p.green =  255;
    else if (green < 0)
	p.green = 0;
    else
	p.green = green;
     // Set the value for blue:
     if (blue > 255)
	p.blue = 255;
    else if (blue < 0)
	p.blue = 0;
    else
	p.blue = blue;
	
    return p;
}

struct color brighter(struct color color2)
{
    color2.red = ((color2.red <= 0) ? (3): ((int) (color2.red * 0.7)));
    color2.green = ((color2.green <= 0) ? (3): ((int) (color2.red * 0.7)));
    color2.blue =  ((color2.blue <= 0) ? (3): ((int) (color2.red * 0.7)));
    return color2;
}

