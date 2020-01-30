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
 
      if (extract(map[y], x, x) == "m") {
room = clone_object("/wizards/walla/ravenloft/outworld/mists.c");
      }
      if (extract(map[y], x, x) == "F") {
        room = clone_object("/wizards/walla/ravenloft/outworld/dforest.c");
      }
      if (extract(map[y], x, x) == "p") {
        room = clone_object("/wizards/walla/ravenloft/outworld/plains.c");
      }
      if (extract(map[y], x, x) == "h") {
        room = clone_object("/wizards/walla/ravenloft/outworld/hills.c");
      }
      if (extract(map[y], x, x) == "f") {
        room = clone_object("/wizards/walla/ravenloft/outworld/forest.c");
      }
      if (extract(map[y], x, x) == "-") {
        room = clone_object("/wizards/walla/ravenloft/outworld/e-w_rd.c");
      }
      if (extract(map[y], x, x) == "/") {
        room = clone_object("/wizards/walla/ravenloft/outworld/sw-ne_rd.c");
      }
      if (extract(map[y], x, x) == "|") {
        room = clone_object("/wizards/walla/ravenloft/outworld/n-s_rd.c");
      }
      if (extract(map[y], x, x) == "'") {
        room = clone_object("/wizards/walla/ravenloft/outworld/nw-se_rd.c");
      }
      if (extract(map[y], x, x) == "~") {
        room = clone_object("/wizards/walla/ravenloft/outworld/bridge.c");
      }
      if (extract(map[y], x, x) == "l") {
        room = clone_object("/wizards/walla/ravenloft/outworld/lake.c");
      }
      if (extract(map[y], x, x) == "r") {
        room = clone_object("/wizards/walla/ravenloft/outworld/river.c");
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
        environ = clone_object("wizards/walla/ravenloft/outworld/environment");
 

 
players = allocate(1);
        player_x = allocate(1);
        player_y = allocate(1);
        map = allocate(40);
 
map[0] = "                                                             ";
map[1] = "                                                             ";
map[2] = "                                                             ";
map[3] = "                                                             ";
map[4] = "      mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm      ";
map[5] = "      mmm?mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm      "; 
map[6] = "      mmmmmmmmmmFFFFFFFFFF?fffffffffppppppppfffFFFFmmmm      ";
map[7] = "      mmmmmmhhhrrrffffffff|ffffffffffffffffffffffFF?mmm      ";  
map[8] = "      mmmhhhhhhhrrrppp/------------------'pppppppffFmmm      "; 
map[9] = "      mmmpppppppprrrpp|ppppppppppppppppppp'ppppppffFFmm      ";
map[10] ="      mmpppppppppprrpp|pppppppppppppppppppp'ppppppffFmm      ";
map[11] ="      mmpppppppppprrpp|ppppppFfllllllfFppppp'ppppppffmm      ";
map[12] ="      mmpppppppppprrp/ppppppFfllllllllfFppppp'pppppffmm      ";
map[13] ="      mmppppppppprrp/pppppppfrllll?llllfFhhhh|ppppppfmm      ";
map[14] ="      mmffffffffrrp/pppphhhhrrfllllllllrrrrrh|pppppffmm      ";
map[15] ="      mmfffffffrrp/hhhhhhhhrrhFflllllllrrrrrr~rrpffFFmm      ";
map[16] ="      mmfffffrrpp/pppppppprrhhhFfllllllfFhhhh|rrrrFFFmm      ";
map[17] ="      mmffffrrpp/pppppppprrhhhhhFfffffFhhhhh/ppprrrFFmm      ";
map[18] ="      mmFFFrrpp/---'pppprrfffffffffffffffff/pppppprr mm      ";
map[19] ="      mm---~~-/ppppp'pprrppppppppppppppppp/pppppppprrmm      ";
map[20] ="      mmFFFFrrppppppp'rrpppp?------------/pppppppppffmm      ";
map[21] ="      mmFFFFFrrrrrrrrr~rppppppppppppppphhhhh^^^^^^^^^mm      ";
map[22] ="      mmmhhhhhhrrrrrrrp' pppppppppphhhhhhh^^/-----?mmmm      ";
map[23] ="      mmmmmhfffffff?pppp'------------------/^^^^^^mmmmm      ";
map[24] ="      mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm      ";
map[25] ="      mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm      ";
map[26] ="                                                             ";
map[27] ="                                                             ";
map[28] ="                                                             ";
map[29] ="                                                             ";
map[30] ="                                                             ";



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
 
