// Originally by Onarion (?)
// Some fixes by Nalle '02 

object rooms, environ, list_x, list_y;
string players;
int player_x, player_y;
string map;

reset(arg) {
  if (arg) return 0;
  start();
}

move_living(string dir, int x, int y) {
  object room, living, ob, last_room; 
  int i;
  string file,str;
  if (dir == "X") { /* ei mitaan */ }
  if (dir == "east") x += 1;
  if (dir == "south") y += 1;
  if (dir == "north") y -= 1;
  if (dir == "west") x -= 1;
  if (dir == "northeast") { x += 1; y -= 1; }
  if (dir == "southeast") { x += 1; y += 1; }
  if (dir == "northwest") { x -= 1; y -= 1; }
  if (dir == "southwest") { x -= 1; y += 1; }
  i = 0;
  if (!room) {
    list_x = 0;
    list_x = list_y[y];
    room = list_x[x];
  }
  if (!room) {
    str = extract(map[y], x, x);
    room = check_rooms(str);
    if(room == 1) return 1;
    if (room) {
      room->set_coordinates(x,y);
      list_x = list_y[y];
      list_x[x] = room;
    }
  }
  i = 0;
  file = this_object()->check_special_coords(x,y, dir);
  if(file) {
    file->loadaus();
    room = find_object(file);
  }
  if(room == 1) return 1;
  if (!room) return 0;
  if(this_player()->query_wiz() && objectp(room))
        tell_object(this_player(), "room: "+file_name(room)+"\n");
  this_player()->move_player(dir, room);
  return 1;
}

draw_map(int x,int y,int big, string ldesc) {
  int e, i;
  string str,light_level,size, sdesc;
  string tmp,tmp2,tmp3, line;
  light_level = this_player()->test_dark();    
  line = allocate(20);
  if(ldesc)     {
    while(i <= 4 && sscanf(ldesc, "%s\n%s", line[i], ldesc) == 2) 
    {
      i++;
    }
                }

  if (!size) {
    size = 4;
    sdesc = lower_case(environment(this_player())->short());
    if(sdesc == "forest") size = 3;
    if(sdesc == "great forest") size = 2;
    if(sdesc == "hills") size = 3;
    if(sdesc == "high hills") size = 3;
  }
  if (big) { size += 2; }
  if (light_level < 3) { size--; }
  if (light_level < 2) { size--; }
  if (light_level < 1) { size--; }
  str = "\n";
  tmp = "      ";
//  tmp = "       ";
  e = 1;
  i = 0;
  write("\n");
  while(e < size) {
    if(!line[i]) line[i] = "";
    tmp3 = line[i] +"\n";
    i++;
    tmp2 = extract(map[y - (size-e)], x - e, x + e);
    str += extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp2 + tmp3;
  write(extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + return_colors(tmp2) + 
        extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp3);
    e++;
  }
  if(!line[i]) line[i] = "";
  tmp3 = line[i] +"\n";
  i ++;
  tmp2 = extract(map[y], x - size, x - 1)+ "*" +extract(map[y], x + 1, x + size);
  str += extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp2 + tmp3;
  write(extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + return_colors(tmp2) + 
        extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp3);

  e = size-1;
  while(e > 0) {
    if(!line[i]) line[i] = "";
    tmp3 = line[i] +"\n";
    i ++;
    tmp2 = extract(map[y + size-e], x - e, x + e);
    str += extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp2 + tmp3;
    write(extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + return_colors(tmp2) + 
          extract(tmp, 0, strlen(tmp)-strlen(tmp2)/2) + tmp3);
    e--;
  }

  return 0;
}

get_colors(string str) {
  string jees,tmp,tmp2;
  int i;
  while(i<strlen(str)) {
    tmp = extract(str,i,i);
    tmp2 = 0;
    if(tmp == "p") tmp2 = "[1;1;33m";
    if(tmp == "f") tmp2 = "[1;0;32m";
    if(tmp == "F") tmp2 = "[1;0;32m";
    if(tmp == "~") tmp2 = "[1;1;34m";
    if(tmp == "r") tmp2 = "[1;1;34m";
    if(tmp == "R") tmp2 = "[1;1;34m";
    if(tmp == "l") tmp2 = "[1;1;34m";
    if(tmp == "|") tmp2 = "[1;1;30m";
    if(tmp == "-") tmp2 = "[1;1;30m";
    if(tmp == "+") tmp2 = "[1;1;30m";
    if(tmp == "h") tmp2 = "[1;0;35m";
    if(tmp == "H") tmp2 = "[1;0;35m";
//
    if(tmp == "n") tmp = "\n";
    if(tmp2) write(sprintf("%c",27)+tmp2+tmp+sprintf("%c",27)+"[0m");
    else write(tmp);
    i ++;
  }
  return 1;
}

return_colors(string str) {
  string final,tmp,tmp2;
  int i;

  // Make sure we don't fuck up terminals 
  if(!this_player()->query_terminal()) return str;
  final="";

  for(i=0;i<strlen(str);i++) {
    tmp = extract(str,i,i);
    tmp2 = 0;
    if(tmp == "p") tmp2 = "[1;1;33m";
    if(tmp == "f") tmp2 = "[1;0;32m";
    if(tmp == "F") tmp2 = "[1;0;32m";
    if(tmp == "~") tmp2 = "[1;1;34m";
    if(tmp == "r") tmp2 = "[1;1;34m";
    if(tmp == "R") tmp2 = "[1;1;34m";
    if(tmp == "l") tmp2 = "[1;1;34m";
    if(tmp == "|") tmp2 = "[1;1;30m";
    if(tmp == "-") tmp2 = "[1;1;30m";
    if(tmp == "+") tmp2 = "[1;1;30m";
    if(tmp == "h") tmp2 = "[1;0;35m";
    if(tmp == "H") tmp2 = "[1;0;35m";

    if(tmp == "n") tmp = "\n";
    if(tmp2) final+=sprintf("%c",27)+tmp2+tmp+sprintf("%c",27)+"[0m";
    else final+=tmp;
  }
  return final;
}

start() {
  int i;
/*  if(this_player()->query_wiz()) write("Starting map system....."); */
  players = allocate(1);
  player_x = allocate(1);
  player_y = allocate(1);
  map = this_object()->get_map();
  if(!map) {
    map = allocate(10);
    map[0] = "map_daemon_allocate";
  }
  list_y = allocate(sizeof(map));
  list_x = allocate(strlen(map[0]));
  while(i<sizeof(list_y)) {
    list_y[i] = allocate(sizeof(list_x));
    i += 1;
  }
}

