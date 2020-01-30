object rooms, environ;
string players;
int player_x, player_y;
string map;

check_special_coords(x,y) {
    if (x == 4 && y == 6) {
        return "/world/hallway/hall5";
    }
    return 0;
}

reset(arg) {
    if (arg) {
        return 0;
    }
    start();
}

move_living(dir, x_coord, y_coord) {
    object room, living, ob, last_room; 
    int x, y, i;
    string file;

    if (dir == "X") {
        x = x_coord;
        y = y_coord;
    }
    if (dir == "east") {
        x = x_coord + 1;
        y = y_coord;
    }
    if (dir == "south") {
        x = x_coord;
        y = y_coord + 1;
    }
    if (dir == "north") {
        x = x_coord;
        y = y_coord - 1;
    }
    if (dir == "west") {
        x = x_coord - 1;
        y = y_coord;
    }
    if (dir == "northeast") {
        x = x_coord + 1;
        y = y_coord - 1;
    }
    if (dir == "southeast") {
        x = x_coord + 1;
        y = y_coord + 1;
    }
    if (dir == "northwest") {
        x = x_coord - 1;
        y = y_coord - 1;
    }
    if (dir == "southwest") {
        x = x_coord - 1;
        y = y_coord + 1;
    }
    
    i = 0;
    while (i < sizeof(players)) {
        if (players[i] != 0) {
            if (player_x[i] == x) {
                if (player_y[i] == y) {
                    living = find_player(lower_case(players[i]));
                    if (living) {
                        room = environment(living);
                        i = sizeof(players) + 1;
                    }
                    else {
                        write("Bugged: no such a player");
                    }
                }
            }
        }
        i += 1;
    }
    if (!room) { 
	room = present(x+","+y, environ);
    }
    if (!room) {
      if (extract(map[y], x, x) == "f") {
        room = clone_object("/wizards/celtron/forest/forest1.c");
      }
      if (extract(map[y], x, x) == "F") {
        room = clone_object("/wizards/celtron/forest/forest2.c");
      }
      if (extract(map[y], x, x) == "b") {
        room = clone_object("/wizards/celtron/forest/bushes.c");
      }
      if (extract(map[y], x, x) == "h") {
        room = clone_object("/wizards/celtron/forest/hills.c");
      }
      if (room) {
         room->set_coordinates(x,y);
         room->set_id(x+","+y);
	 move_object(room, environ);
      }
    }
    i = 0;
    if (check_special_coords(x,y)) {
        file = check_special_coords(x,y);
        room = file;
    }         
    
    if (!room) {
        return 0;
    }
    this_player()->move_player(dir,room);
    return 1;
}

draw_map(x,y,big) {
    write("\n");
    if (big) {
       write(extract(map[y - 3], x - 5, x + 5) + "\n");
       write(extract(map[y - 2], x - 5, x + 5) + "\n");
       write(extract(map[y - 1], x - 5, x + 5) + "\n");
       write(extract(map[y], x - 5, x - 1) + "*" + extract(map[y], x + 1, x + 5)+"\n");
       write(extract(map[y + 1], x - 5, x + 5) + "\n");
       write(extract(map[y + 2], x - 5, x + 5) + "\n");
       write(extract(map[y + 3], x - 5, x + 5) + "\n");
       return 1;
    }
    write(extract(map[y - 2], x - 3, x + 3) + "\n");
    write(extract(map[y - 1], x - 3, x + 3) + "\n");
    write(extract(map[y], x - 3, x - 1) + "*" + extract(map[y], x + 1, x + 3) + "\n");
    write(extract(map[y + 1], x - 3, x + 3) + "\n");
    write(extract(map[y + 2], x - 3, x + 3) + "\n");
}

start() {
        write("Starting map system.....");
	environ = clone_object("wizards/celtron/forest/environment");
        players = allocate(1);
        player_x = allocate(1);
        player_y = allocate(1);
        map = allocate(46);
map[0] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[1] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[2] =  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[3] =  "^^^^^^^^^^^^hhh^^^^^^^^^^^^^^^^hhhhhhbbhhhhhhhhhhh^^^^^^^^^^^^^^^^^^^^";
map[4] =  "^^^^^^^^^^hhhhhhhh^^^^^^^^hhhhhbbbbffffffffbbbbhhhhhhhhh^^^^^^^^^^^^^^";
map[5] =  "^^^^^^^hhhhhhbbhhhh^^^^hhhhhhbbbbffffffffffffbbbbbbbbbhhhhhhhhh^^^^^^^";
map[6] =  "^^^^?hhhhhbbbbbbbhhh^hhhhhbbbbbfffffffffffffffffffbbbbbhhhhhhhhhh^^^^^";
map[7] =  "^^^hhhhhbbbbbffbbbhhhhhhbbbbffffffffffFFffFfffffffffbbbbbhhhhhhhhhh^^^";
map[8] =  "^^^hhhbbbbbfffffbbbbhhbbbbfffffffffFFFFFFFFFFfffffffffbbbbhhhhhhhhh^^^";
map[9] =  "^^^hhhhhbbffffffffbbbhbbfffffffffFFFFFFFFFFFFFFfffffffffbbbbbhhhhhh^^^";
map[10] = "^^^hhhhbbbbbffffbbbbhhbbbbffffffffFFFFFFFFfffFFffffffffbbbbbhhhhhhh^^^";
map[11] = "^^^^hhhhhbbbbfbbbbbhhhhhbbbbffffffffFFFFFffffffffffffbbbbbhhhhhhh^^^^^";
map[12] = "^^^^^^hhhhbbbbbbbhhhhhhhbbbbbbfffffffFFffffffffffbbbbbbhhhhhhh^^^^^^^^";
map[13] = "^^^^^^^^^hhhhbbhhhhhhhhhhhhbbbbbffffffffffffffbbbbbbbhhhhhh^^^^^^^^^^^";
map[14] = "^^^^^^^^^^^^hhhhhhhhhhhhhhhbbbbbbbbfffffffbbbbbbbhhhhhh^^^^^^^^^^^^^^^";
map[15] = "^^^^^^^^^^^^^^^hhhhh^^hhhhhhbbbbbbbbbfffbbbbbbhhhhhh^^^^^^^^^^^^^^^^^^";
map[16] = "^^^^^^^^^^^^^^^^hh^^^^^^^^^hhhhhbbbbbbbbbbhhhhhh^^^^^^^^^^^^^^^^^^^^^^";
map[17] = "^^^^^^^^^^^^^^^hh^^^^^^^^^^^^^^hhhhhbbhhhhhh^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[18] = "^^^^^^^^^^^^^^^h^^^^^^^^^^^^^^^^^^^hhhhh^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[19] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[20] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";
map[21] = "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^";

}                                                  

long() {
    write("This is the forest outmap object\n");
}

id() {
    return "forest_map_object";
}

name() {
    return "forest_map_object";
}

get() {
    return 0;
}

