object rooms, environ, list_x, list_y;
string players;
int player_x, player_y;
string map;

check_special_coords(x,y) {
    if (x == 110 && y == 40) {
        return "/wizards/irmeli/area2/entrance";
    }
    if (x == 137 && y == 30) {
        return "/wizards/irmeli/pena/entrance";
    }
    if (x == 189 && y == 37) {
        return "/wizards/aarrgh/nyxi/entrance";
    }
    if (x == 157 && y == 9) {
        return "/wizards/walla/area/sgate";
    }
    if (x == 197 && y == 35) {
        return "/wizards/celtron/maze/entrance";
    }
    if (x == 172 && y == 41) {
        return "/wizards/morgoth/cannibal/room/path1";
    }
    if (x == 136 && y == 36) {
        return "/wizards/manta/hill/room1";
    }
    if (x == 83 && y == 17) {
      return "/wizards/bulut/forest/forest1";
    }
    if (x == 121 && y == 37) {
        return "/world/city/eastgate";
    }
    if (x == 113 && y == 29) {
      return "/wizards/bulut/cave/entrance";
    }
    if (x == 116 && y == 31) {
        return "/world/mine/path1";
    }
    if (x == 117 && y == 37) {
        return "/world/city/westgate";
    }
    if (x == 119 && y == 36) {
        return "/world/city/northgate";
    }
    if (x == 119 && y == 38) {
        return "/world/city/southgate";
    }
    if (x == 36 && y == 32) {
        return "/world/fighter/ranger";
    }
    if (x == 211 && y == 24) {
        return "/world/hallway/hall";
    }
    if (x == 85 && y == 39) {
        return "/wizards/bulut/forl/ulos";
    }
    if (x == 96 && y == 34) {
        return "/wizards/nalle/area/entrance";
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
        room = clone_object("/world/out/forest.c");
      }
      if (extract(map[y], x, x) == "F") {
        room = clone_object("/world/out/gforest.c");
      }
      if (extract(map[y], x, x) == "p") {
        room = clone_object("/world/out/plains.c");
      }
      if (extract(map[y], x, x) == "-") {
        room = clone_object("/world/out/w_e_road.c");
      }
      if (extract(map[y], x, x) == "|") {
        room = clone_object("/world/out/n_s_road.c");
      }
      if (extract(map[y], x, x) == "/") {
        room = clone_object("/world/out/ne_sw_ro.c");
      }
      if (extract(map[y], x, x) == "+") {
        room = clone_object("/world/out/roadcros.c");
      }
      if (extract(map[y], x, x) == "h") {
        room = clone_object("/world/out/hills.c");
      }
      if (extract(map[y], x, x) == "H") {
        room = clone_object("/world/out/highhill.c");
      }
      if (extract(map[y], x, x) == "r") {
        room = clone_object("/world/out/river.c");
      }
      if (extract(map[y], x, x) == "=") {
        room = clone_object("/world/out/bridge.c");
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
	if(file) { room = file; }
    }         
    if (!room) {
        return 0;
    }
    this_player()->move_player(dir,room);
    return 1;
}

draw_map(x,y,big) {
    string str,light_level,size;
    light_level = this_player()->test_dark();    
    if (!size) {
      size = 4;
      if (environment(this_player())->short() == "Forest") {
	size = 3;
      }
      if (environment(this_player())->short() == "Great forest") {
	size = 2;
      }
      if (environment(this_player())->short() == "Hills") {
	size = 3;
      }
      if (environment(this_player())->short() == "High hills") {
	size = 3;
      }
    }
    if (big) { size += 2; }
    if (light_level < 3) { size -= 1; }
    if (light_level < 2) { size -= 2; }
    if (light_level < 1) { size -= 1; }
    if (size == 1) {
      str = "";
      str += " ";
      str += extract(map[y - 1], x - 1, x + 1) + "\n";
      str += extract(map[y],x-2,x-1)+"*"+extract(map[y],x+1,x+2) +"\n";
      str += " ";
      str += extract(map[y + 1], x - 1, x + 1) + "\n";
      if(this_player()->query_terminal() && big) get_colors(str);
      else write(str);
      return;
    }
    if (size == 2) {
      str = "";
      str += " ";
      str += extract(map[y - 2], x - 2, x + 2) + "\n";
      str += extract(map[y - 1], x - 3, x + 3) + "\n";
      str += extract(map[y],x-3,x-1)+"*"+extract(map[y],x+1,x+3)+"\n";
      str += extract(map[y + 1], x - 3, x + 3) + "\n";
      str += " ";
      str += extract(map[y + 2], x - 2, x + 2) + "\n";
      if(this_player()->query_terminal() && big)
	get_colors(str);
      else
	write(str);
      return;
    }
    if (size == 3) {
      str = "";
      str += "   ";
      str += extract(map[y - 3], x - 2, x + 2) + "\n";
      str += " ";
      str += extract(map[y - 2], x - 4, x + 4) + "\n";
      str += extract(map[y - 1], x - 5, x + 5) + "\n";
      str += extract(map[y],x-5,x-1)+"*"+extract(map[y],x+1,x+5)+"\n";
      str += extract(map[y + 1], x - 5, x + 5) + "\n";
      str += " ";
      str += extract(map[y + 2], x - 4, x + 4) + "\n";
      str += "   ";
      str += extract(map[y + 3], x - 2, x + 2) + "\n";
      if(this_player()->query_terminal() && big)
        get_colors(str);
      else
        write(str);
      return;
    }
    if (size == 4) {
      str = "\n";
      str += "   ";
      str += extract(map[y - 4], x - 4, x + 4) + "\n";
      str += " ";
      str += extract(map[y - 3], x - 6, x + 6) + "\n";
      str += extract(map[y - 2], x - 7, x + 7) + "\n";
      str += extract(map[y - 1], x - 7, x + 7) + "\n";
      str += extract(map[y],x-7,x-1)+"*"+extract(map[y],x+1,x+7)+"\n";
      str += extract(map[y + 1], x - 7, x + 7) + "\n";
      str += extract(map[y + 2], x - 7, x + 7) + "\n";
      str += " ";
      str += extract(map[y + 3], x - 6, x + 6) + "\n";
      str += "   ";
      str += extract(map[y + 4], x - 4, x + 4) + "\n";
      if(this_player()->query_terminal() && big)
        get_colors(str);
      else
        write(str);
      return;
    }
    if (size == 5) {
      str = "\n";
      str += "      ";
      str += extract(map[y - 5], x - 3, x + 3) + "\n";
      str += "   ";
      str += extract(map[y - 4], x - 6, x + 6) + "\n";
      str += " ";
      str += extract(map[y - 3], x - 8, x + 8) + "\n";
      str += extract(map[y - 2], x - 9, x + 9) + "\n";
      str += extract(map[y - 1], x - 9, x + 9) + "\n";
      str += extract(map[y],x-9,x-1)+"*"+extract(map[y],x+1,x+9)+"\n";
      str += extract(map[y + 1], x - 9, x + 9) + "\n";
      str += extract(map[y + 2], x - 9, x + 9) + "\n";
      str += " ";
      str += extract(map[y + 3], x - 8, x + 8) + "\n";
      str += "   ";
      str += extract(map[y + 4], x - 6, x + 6) + "\n";
      str += "      ";
      str += extract(map[y + 5], x - 3, x + 3) + "\n";
      if(this_player()->query_terminal() && big)
        get_colors(str);
      else
        write(str);
      return;
    }
    if (size == 6) {
      str = "\n";
      str += "       ";
      str += extract(map[y - 6], x - 4, x + 4) + "\n";
      str += "    ";
      str += extract(map[y - 5], x - 7, x + 7) + "\n";
      str += "  ";
      str += extract(map[y - 4], x - 9, x + 9) + "\n";
      str += " ";
      str += extract(map[y - 3], x - 10, x + 10) + "\n";
      str += extract(map[y - 2], x - 11, x + 11) + "\n";
      str += extract(map[y - 1], x - 11, x + 11) + "\n";
      str += extract(map[y],x-11,x-1)+"*"+extract(map[y],x+1,x+11)+"\n";
      str += extract(map[y + 1], x - 11, x + 11) + "\n";
      str += extract(map[y + 2], x - 11, x + 11) + "\n";
      str += " ";
      str += extract(map[y + 3], x - 10, x + 10) + "\n";
      str += "  ";
      str += extract(map[y + 4], x - 9, x + 9) + "\n";
      str += "    ";
      str += extract(map[y + 5], x - 7, x + 7) + "\n";
      str += "       ";
      str += extract(map[y + 6], x - 4, x + 4) + "\n";
      if(this_player()->query_terminal() && big)
        get_colors(str);
      else
        write(str);
      return;
    }
}

get_colors(string str) {
  string jees,tmp,tmp2;
  int i;
  while(i<strlen(str)) {
    tmp = extract(str,i,i);
    tmp2 = 0;
    if(tmp == "p") tmp2 = "[1;1;33m";
    if(tmp == "f") tmp2 = "[1;1;32m";
    if(tmp == "F") tmp2 = "[1;1;32m";
    if(tmp == "~") tmp2 = "[1;1;34m";
    if(tmp == "r") tmp2 = "[1;1;34m";
    if(tmp == "R") tmp2 = "[1;1;34m";
    if(tmp == "l") tmp2 = "[1;1;34m";
    if(tmp == "n") tmp = "\n";
    if(tmp2) write(sprintf("%c",27)+tmp2+tmp+sprintf("%c",27)+"[0m");
    else write(tmp);
    i += 1;
  }
  return 1;
}

start() {
  int i;
        write("Starting map system.....");
        players = allocate(1);
        player_x = allocate(1);
        player_y = allocate(1);
        map = allocate(50);
map[0] =  "                                                                                                                                                                                                                        ";
map[1] =  "                                                                                                                                                                                                                        ";
map[2] =  "                                                                                                                                                                                                                        ";
map[3] =  "                                                                                                                                                                                                                        ";
map[4] =  "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[5] =  "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhhhhhh^^^^hhhhhhh~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[6] =  "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~hhhHH^^^^^^^^^^^^HHHhh~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[7] =  "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ppphhHH^^^^^^^^^^^^^^^^^^^^^HHhh~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~###~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[8] =  "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ffffffffffffffffffffffff~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ffpphhH^^^^^^^^^^^^^^^^^^^^^^^^^^^hh~~~~~~~~~~~~~ppp~~~~pppppppp###ppppppppppp~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
map[9] =  "      ~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffffffffffffffffffffffff~~~~~~~~~~~~~~~~~~~~~~~~~~ffffpppphHH^^^^^^^^^^^^^^^^^^^^^^^HHHhhh~~~~~~~~~ppppppppppppppppp###ppppppppppppppppp~~~~~~~~~~~~~~~~~~~~~~~~pppppppppppppppp";
map[10] = "      ~~~~~~~~~~~~~~~~~~fffffffffffffffffffffffffffffffffffffffffff~~~~~~~~~~~~~~~~~~~~fffffffppppphhHH^^^^^^^^^^^^^^^^^^^^^^^^Hhhh~~~~~~pppppppppppppppppppp|pppppppppppppppppppppp~~~~~~~~~~~~~~~ppppppppppppppppppppp";
map[11] = "      ~~~~~~~~~~~~~~~~fffffffffffffffffffffffffffffffffffffffffffffff~~~~~~~~~~~~~~~~ffffffffppppppphhHHHHH^^^^^^^^^^^^^^^^^^^^^^Hhh~~~~ppppppppppppppppppppp+pppppppppppppppppppppppp~~~~~~~~~~~ppppppppppppppppppppppp";
map[12] = "      ~~~~~~~~~~~~~~~ffffffffffffffffffffFFFFFFFFFffffffffffffffffffff~~~~~~~~~~~~~ffffffffppppppppH^^^^^^^^^^^^^^HHH^^^^^^^^^Hhhhp~~~pppppppppppppppppppppp/pppppppppppppppppppppppppprRRRRRRrppppppppppppppppppppppppp";
map[13] = "      ~~~~~~~~~~~~~~ffffffffffffffffFFFFFFFFFFFFFFFFFFFffffffffffffffff~~~~~~~~~~~fffffffpppppppppppHH^^^^^^^^HHHHh+-+HHH^^^^^^Hhhp~~~ppppppppppppppppppppp/ppppppppppppppppppppppppppprRRRrpppppppppppppppppppppppppppp";
map[14] = "      ~~~~~~~~~~~~~~fffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffff~~~~~~~ffffffffffppppppppppppppHHH^^^^HHHhhhpp|hHHHHHHHHhhppp~ppppppppppppppp+-----+ppppppppppppppppppppppppppprrrrpppppppppppppppppppppppppppppp";
map[15] = "      ~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFfffffffffff~~~~~fffffffffffppppppppppppppppppHHHHpppppppp+-+hhhhhhhhppppppppppppppppppp/pppppppppppppppppppppppppppppppprrrrpppppppppppppppppppppppppppppppp";
map[16] = "      ~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFfffffffffffffff~~ffffffffffffppppppppppppppppppppppppppppppppp|pppppppppppppppppppppppppp/pppppppppppppppppppppppppppppppprrrpppppppppppppppppppppppppppppppppp";
map[17] = "      ~~~~~~~~~~~~~~~~fffffffffffffFFFFFFFFF%%FFFFFFFFFFFFfffffffffffffffffffffffff?fpppppppppppppppppppppppppppppppppp|ppppppppppppppppppppppppp/pppppppppppppppppppppppppppppppprrpppppppppppppppppppppppppppppppppppp";
map[18] = "      ~~~~~~~~~~~~~~~~~fffffffffffffFFFFFFFF%%FFFFFFFFFFFFFffffffffffffffffffffffffpppppppppppppppppppppppppppppppppppp|ppppppprpppppppppppppppp/pppppppppppppppppppppppppppppprrrrrrppppppppppppppppppppppppppppphhhhhh";
map[19] = "      ~~~~~~~~~~~~~~~~fffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffffpppppppppppppppppppppppppppppppppppppp+---+pppprrppppppppppppp/pppppppppppppppppppppppppppprrrrpppprrppppppppppppppppppppppppppphhhhhhH";
map[20] = "      ~~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffppppppppppppppppppppppppppppppppppppppppppp|pppppprrpppppppppp/ppppppppppppppppppppppppprrrrrpppppppprrppppppppppppppppppppppppphhhhhhH^";
map[21] = "      ~~~~~~~~~~~~~~~~~ffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffffppppppppppppppppppppppppppppppppppppppppppppp|ppppppprRrppppppp/pppppppppppppppprrrrrrrrrrrrrprpppppppprrpppppppppppppppppppppppphhhhhhH^^";
map[22] = "      ~~~~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffpppppppppppppppppppppppppppppppppppppppppppppp|pppppppprRrppppp/ppppppppppppprrrrppprrrppprrppppppppppppprrpppppppppppppppppppppphhhhhhH^^^";
map[23] = "      ~~~~~~~~~~~~~~~~~ffffffffffffffFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffppppppppppppppppppppppppppppppppppppppppppppppp+--+pppppprRrppp/pppppppppppprrpppprrrpppprrrppppppppppppppprrppppppppppppppppppphhhhhhHH^^^^";
map[24] = "      ~~~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffffppppppppppppppppppppppppppppppppppphHhhpppppppppppp|pppppp+-==-+ppppppppppppppppprrpppppprrpppppppppppppppppprpppppppppppppppppphhhhhhH^?^^^^";
map[25] = "      ~~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFfffffffffffffffffffffpppppppppppppppppppppppppppppppppphH^^Hhppppppppppp|ppppp/ppprRrppppppppppppppprrrppppprrrpppppppppppppppppppprpppppppppppppppphhhhhhH^^^^^^^";
map[26] = "      ~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffffppppppppppppppppppppppppppppppppppphH^^Hhppppppppppp|pppp/pppppprrrrppppppppppppppppppprrrrllllpppppppppppppppprppppppppppppphhhhhhhHH^^^^^^^^";
map[27] = "      ~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffppppppppppppppppppppppppppppppppppppphH^^Hhpppppppppp+---+ppppppppprrrrrrrpppppppppppllllllllllllllpppppppppppppppppppppppppphhhhhhHH^^^^^^^^^^";
map[28] = "      ~~~~~~~~~~~~~~fffffffffffFFFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffppppppppppppppppppppppppppppppppppppppphH^^^Hhpppppppp/pppppppppppppppppprrrrrrrrrpppllllllllllllllllllpppppppppppppppppppppppphhhhHH^^^^^^^^^^^^";
map[29] = "      ~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffppppppppppppppppppppppppppppppppppppppppphH?^^^Hhppppp/ppppppppppppppppppppppprrrrrrrlllllllllllllllllpppppppppppppppppppppppphhhhhH^^^^^^^^^^^^^H";
map[30] = "      ~~~~~~~~~~~~~~fffffffffffFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffpppppppppppppppppppppppppppppppppppppppppphH^^^^Hhppp/ppppppppppppp?pppppppppppppprrlllllllllllllllllppppppppppppppppppppppppphhhhH^^^^^^^^^^^^Hhh";
map[31] = "      ~~~~~~~~~~~~~~~~ffffffffffFFFFFFFFFFFFFFFFFFFFFffffffffffffffffffppppppppppppppppppppppppppppppprpppppppppphH^?^Hhpp/ppppppppppppppppppppppppppppppppplllllllllllllpppppppppppppppppppppppppphhhhH^^^^^^^^^^^Hhhhh";
map[32] = "      ~~~~~~~~~~~~~~~ffffffffffFFFFF?FFFFFFFFFFFFFFFFFfffffffffffffffffppppppppppppppppppppppppppppppprrpppppprpphHH|hhpp/pppppppppppppppppppppppppppppppppppllllllllllrrpppppppppppppppppppppppphhhhhH^^^^^^^^^Hhhhhhhp";
map[33] = "      ~~~~~~~~~~~~~~~ffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffffpppppppppppppppppppppppppppppprrpppprpppphh|ppp/ppppppppppppppppppppppppppppppppppppplllllppprrrrrpppppppppppppppppppphhhhhhH^^^^^^^^Hhhhhhhppp";
map[34] = "      ~~~~~~~~~~~~~~~fffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffppppppppppppppppppppp?ppppppprrprrppppppp+--+pppppppppppppppppppppppppppppppppppppppppppppppprrrrrrrppppppppppppppphhhhhhH^^^^^^^Hhhhhhhppppp";
map[35] = "      ~~~~~~~~~~~~~~fffffffffFFFFFFFFFFFFFFFFFFFF###FFFFFFFFffFFFFfffffffffffpppppppppppppppppp+-----+ppprrrppppppppppp|pppppppppppppppppppppppppppppppppppppppppppppppppprrrrrrrrpppppppppphhhhhhhH^?^^^^^Hhhhhhhpppppp";
map[36] = "      ~~~~~~~~~~~~~~fffffffffffFFFFFFFFFFFFFFFFFF###ffffFFfffFFFFFFFFfffffffffffpppppppppppppp/pppppp|ppprrpppppppppp#####pppppppppppppp?pppppppppppppppppppppppppppppppppppprrrrrrppppppppphhhhhhH^^^^^^^Hhhhhhhppppppp";
map[37] = "      ~~~~~~~~~~~~~~~ffffffffffffFFFFFFFFFFFFFFFF###FFFffffFFFFFFFFFFfffffffffffppppppppppppp/ppppppp+---==----------#####--------------+ppppppppppppppppppppppppppppppppppppppprrrrrrrrrrhhh?hhhH^^^^^^^Hhhhhhhpppppppp";
map[38] = "      ~~~~~~~~~~~~~~~~ffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFffffffffffffffff+-------+ppppppppppprrppppppppppp#####pppppppppppppppppppppppppppppppppppppppppppppppppppppppppprrrpphhhhhhhH^^^^^^^Hhhhhhhppppppppp";
map[39] = "      ~~~~~~~~~~~~~~~~~ffffffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFfffffffffffffffffff?ppppppppppppppppprrpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppprrrphhhhhhH^^^^^^^^Hhhhhhpppppppppp";
map[40] = "      ~~~~~~~~~~~~~~~~~~~ffffffffffffffffffffffFFFFFFFFFFFFFFFFFfffffffffffffffffffffpppppppppppppppppprrppppp?pppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppphhhhhhHH^^^^^^^^^Hhhhhhhppppppppp";
map[41] = "      ~~~~~~~~~~~~~~~~~~~~~~~~~ffffffffffffffffffffffffffffffffffffffffffffffffffffppppppppppppppppppprrpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppp?ppppphhhhhHH^^^^^^^^^^Hhhhhhppppppppppp";
map[42] = "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~fffffffffffffffffffffffffffffffffffffffffffffffppppppppppppppppppprrpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppphhhhhhH^^^^^^^^^^^^Hhhhhhhpppppppppp";
map[43] = "      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ffffffffffffffffffffffffffffffffffffffppppppppppppppppppprrpppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppppphhhhhhhH^^^^^^^^^^^^^Hhhhhhppppppppppp";
map[44] = "                                                                                                                                                                                                                        ";
map[45] = "                                                                                                                                                                                                                        ";
map[46] = "                                                                                                                                                                                                                        ";
map[47] = "                                                                                                                                                                                                                        ";
map[48] = "																											   ";
list_y = allocate(sizeof(map));
list_x = allocate(strlen(map[3]));
while(i<sizeof(list_y)) {
  list_y[i] = allocate(sizeof(list_x));
  i += 1;
}
}

long() {
    write("This is the outmap object\n");
}

id() {
    return "map_object";
}

name() {
    return "map_object";
}

get() {
    return 0;
}
