init() {
add_action("funkki", "enter");
}

funkki(str) {
/* str == komento - "enter", mikali siis komento on alkanut enterilla, etta tata
funktioo ees callataan */
  if(str == "window") {
    write("You jump out from the window and realize that you are 20 feets above "+
	"ground!\n");
    write("You start falling..\n");
    write("You drop on the ground!\n");
    this_player()->reduce_hit_points(this_player->query_size()*10);
    return 1;
  } 
}

