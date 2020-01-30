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
 
---
Add here special places. Moves player to the room in the defined dir,
when he moves to coordinates x,y. */
 
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
      if (extract(map[y], x, x) == "\") {
        room = clone_object("/wizards/walla/ravenloft/outworld/nw-se_rd.c");
      }
      if (extract(map[y], x, x) == "=") {
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
        map = allocate(500);
 

map[0] = "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
map[1] = "mm?mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm"; 
map[2] =  "mmmmmmmmmmFFFFFFFFFF?fffffffffppppppppfffFFFFmmmm";
map[3] =  "mmmmmmhhhrrrffffffff|ffffffffffffffffffffffFF?mmm";          
map[4] =  "mmmhhhhhhhrrrppp/------------------\pppppppffFmmm";                 
map[5] =  "mmmpppppppprrrpp|ppppppppppppppppppp\ppppppffFFmm";
map[6] =  "mmpppppppppprrpp|pppppppppppppppppppp\ppppppffFmm";
map[7] =  "mmpppppppppprrpp|ppppppFfllllllfFppppp\ppppppffmm";
map[8] =  "mmpppppppppprrp/ppppppFfllllllllfFppppp\pppppffmm";
map[9] =  "mmppppppppprrp/pppppppfrllll?llllfFhhhh|ppppppfmm";
map[10] = "mmffffffffrrp/pppphhhhrrfllllllllrrrrrh|pppppffmm";
map[11] = "mmfffffffrrp/hhhhhhhhrrhFflllllllrrrrrr=rrpffFFmm";
map[12] = "mmfffffrrpp/pppppppprrhhhFfllllllfFhhhh|rrrrFFFmm";
map[13] = "mmffffrrpp/pppppppprrhhhhhFfffffFhhhhh/ppprrrFFmm";
map[14] = "mmFFFrrpp/---\pppprrfffffffffffffffff/pppppprr mm";
map[15] = "mm---==-/ppppp\pprrppppppppppppppppp/pppppppprrmm";
map[16] = "mmFFFFrrppppppp\rrpppp?------------/pppppppppffmm";
map[17] = "mmFFFFFrrrrrrrrr=rppppppppppppppphhhhh^^^^^^^^^mm";
map[18] = "mmmhhhhhhrrrrrrrp\ pppppppppphhhhhhh^^/-----?mmmm";
map[19] = "mmmmmhfffffff?pppp\------------------/^^^^^^mmmmm";
map[20] ="mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
map[21] ="mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
 
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
 

