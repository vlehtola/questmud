object rooms, environ;
string players;
int player_x, player_y;
string list_y,list_x;
string map;
int monsuluku;
 
query_number() {
  return monsuluku;
}
 
add_number() {
  monsuluku += 1;
}
 

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
    if (!room) {
        list_x = 0;
        list_x = list_y[y];
        room = list_x[x];
    }
    if (!room) {
 

      if (extract(map[y], x, x) == "f") {
        room = clone_object("/wizards/walla/testi/map/forest1.c");
      }
      if (extract(map[y], x, x) == "F") {
        room = clone_object("/wizards/walla/testi/map/forest2.c");
      }
      if (extract(map[y], x, x) == "b") {
        room = clone_object("/wizards/walla/testi/map/bushes.c");
      }
      if (extract(map[y], x, x) == "h") {
        room = clone_object("/wizards/walla/testi/map/hills.c");
      }
      if (extract(map[y], x, x) == "l") {
        room = clone_object("/wizards/walla/testi/map/lake.c");
      }

      if (room) {
         room->set_coordinates(x,y);
         list_x = list_y[y];
         list_x[x] = room;
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
        int i;
        write("Starting map system.....");
 
        environ = clone_object("wizards/walla/testi/map/environment");
 
 
        players = allocate(1);
        player_x = allocate(1);
        player_y = allocate(1);
        map = allocate(22);

         /*  0      1         2         3         4         5         6         7 */
        /* 1234567890123456789012345678901234567890123456789012345678901234567890 */
map[0] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[1] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[2] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffff~~~~~~";
map[3] =  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pppppppppppppppfffffffffffff~~~";
map[4] =  "~~~~~~~~~~~~~~~~~hhhh~~~~~~~~~~ppppppppppppppppppppppppppfffffffffff~~";
map[5] =  "~~~~~~~~~~~~~~~~hhhhhh~~~~~~~~~pbbbbbbbbbbbbbbbbbbbbbbbbbbbbfffffff~~~";
map[6] =  "~~~~~~~~~~~~~~hhhhhhffFFFFFF~~~~bbbbbbbbbbbbbbbbbbbbb?bbbbbbbbfffff~~~";
map[7] =  "~~~~~hhhhh~~~hhhhhhfffFFFFFFF~~~~~pppppppppppppbppbppbbbbbbbffffffff~~";
map[8] =  "~~~hhhhhhhhhhhhhhhhhffffFFFFFppppppppppbpppppppppbpbppbbbbbbfffffff~~~";
map[9] =  "~~~~~~~hhhhhhhhhhhhhffffF?FFFpppppppppppbpppppppppppbpbbbbbfffffff~~~~";
map[10] = "~~~~~~~~~~~~~~~~hhhhffffFFFlllpppppppppbbppppbpppppbbbbbbffffffff~~~~~";
map[11] = "~~~~~~~~~~~~hhhhhhhfffFFFFlllllppppppppbbpppbppppppppfffffffffff~~~~~~";
map[12] = "~~~~~~~~~~~pppppppppfFFFFFFlllpppppppppbbpbppppbbppppp~~~~~~~~~~~~~~~~";
map[13] = "~~~~~~~~~~~fffffffffffffffffffffffffffppppppppppbppppppppppppp~~~~~hh~";
map[14] = "~~~~~~~~~~~~~~~~~~~~~~~~~~ffffffffffffbbbbbbbbbbbbbbbppppppppp~~~~h?h~";
map[15] = "~~~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffbbbbbbbbbbbppppppppppppp~~~~~hh~";
map[16] = "~~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffbbbbbbbbbppppppppppppppppp~~~~~h~";
map[17] = "~~~~~~~~~~~~~~~~~~~~~~~ffffff?ffffffbbbbbbbbbp~~~~~~~~~~ppppppppp~~~~~";
map[18] = "~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffbbbbbbbbp~~~~~~~~~~~~~pppppppp~~~~";
map[19] = "~~~~~~~~~~~~~~~~~~~~~~ffffffffff~~~~pbbbbbbp~~~~~~~~~~~~~~~~ppppppp~~~";
map[20] = "~~~~~~~~~~~~~~~~~~~~~~~ffffffff~~~~~~pppppp~~~~~~~~~~~~~~~~~~~ppppp~~~";
map[21] = "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
 
 
 
list_y = allocate(sizeof(map));
list_x = allocate(strlen(map[3]));
while(i<sizeof(list_y)) {
  list_y[i] = allocate(sizeof(list_x));
  i += 1;
 }
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
 


