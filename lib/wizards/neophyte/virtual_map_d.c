#include <ansi.h>

/* final version of virtual map daemon //Celtron */

#define MAINFILE	file_name(this_object())
#define AREA_D 		"/daemons/area_d"
#define DEFAULT_MINIMAP_SIZE	4

static int MAX_Y, MAX_X;
static string *no_walk;		/*  '*' stands for allocate */
static mapping rooms;		/* loaded rooms, objects. room = rooms[x+"_"+y] */
static string *mapdata;		/* actual map data, allocs in alloc */
static string mapfile;		/* datafile. txt map */

string *invert_rows(string *tmp);
string get_map_char(int x, int y, int X, int Y, status big);
status check_no_walk(string msymbol);
status generate_room(int x, int y, string msymbol);
int abs(int i);
object get_room(string dir, string dest, int x, int y);

void destruct_loaded_room(int x, int y) {
  string prefix;
  prefix = x+"_"+y;
  if(!rooms[prefix])
	return;
  destruct(rooms[prefix]);
  rooms -= ([ prefix ]);
}

void reset(status arg) {
  if(arg) return;
  no_walk = ({" ", "^", "~", }); /* default no_walk */
  this_object()->start();
  rooms = ([ ]);
  rooms += ([ (string) "load": (object) this_object() ]);
  write("room/virtual_map_d.c loaded.\n");
}

/* called when moving on vmap */
void move_living(object walker, string arg, int x, int y) {
  int ep_cost, hiking, i;
  object room, tmp_room, p_ob, *ob;

  room = get_room(arg,0,x,y);
  if(!room) return;

  if(x && y) {
    ep_cost = this_object()->get_terrain_ep_cost(get_map_char(x,y,0,-1,0));
    if(ep_cost >= 1) ep_cost = ep_cost - 1 + random(2);
    hiking = walker->query_skills("hiking");
    ep_cost -= random(hiking)/10;
    if(ep_cost < 0) ep_cost = 0;
    if (this_player()->query_endurance_points() < (ep_cost+2)) {
      write("You are too exhausted to move any further in this rough terrain.\n");
      return;
    }
    this_player()->reduce_ep(ep_cost);
  }

  /* AMBUSH aka new fiitso added by celtron */

  p_ob = this_player()->query_party();
  /* jos pelaaja ei ole partyssa tai on leaderi TAI leaderi on eri paikassa */
  if((!p_ob || this_player() == p_ob->query_leader()) || environment(p_ob->query_leader()) != room ) {
    tmp_room = (object) MAINFILE->room_loaded(room,x,y, get_map_char(x,y,0,-1,0));
    if(tmp_room && objectp(tmp_room)) {
	room = tmp_room;

        /* partytapauksessa hela party lentaa ambushiin */
    	if(p_ob) {
      	  ob = all_inventory(environment(this_player()) );
      	  for(i=0; i < sizeof(ob); i++) {
        	if(ob[i] && p_ob->is_member(ob[i]))
	  	    move_object(ob[i], room);
      	  }
          /* p_ob */
    	}
    }
  } 
  /* end */

  walker->move_player(arg, room);
}

object get_room(string dir, string dest, int x, int y) {
  object dest_ob;
  string msymbol, file, prefix;
  if(dest && sscanf(dest, "virtual %s %d %d", file, x, y) != 3) {
    write("Move to bad virtual dest.\n");
    return 0;
  } 
  if(file && MAINFILE != file) {
    return file->get_room(dir,dest);
  } else if(!file || dir) { /* normal movement on vmap */
    switch(dir) {
    case "north": y++; break;
    case "south": y--; break;
    case "east":  x++; break;
    case "west":  x--; break;
    case "northwest": y++; x--; break;
    case "northeast": y++; x++; break;
    case "southwest": y--; x--; break;
    case "southeast": y--; x++; break;
    case "X":
    default:
    }
  }
  /* allow move to (0,0) by prohibiting move to (0,-1) */
  msymbol = get_map_char(x,y,0,-1,0);
  prefix = x+"_"+y;
  if(this_player()->query_wiz()) write("xy "+prefix+"\n");

  if(!rooms[prefix] && !generate_room(x,y,msymbol)) {
    if(check_no_walk(msymbol)) {
      write("You cannot go that way.\n");
      return 0;
    }
    // write("Failed.\n");
    return 0;
  }
  return rooms[prefix];
}

status generate_room(int x, int y, string msymbol) {
  string file;
  object room;
  if(rooms[x+"_"+y]) return 1;
  /* check for exits from vmap */
  file = this_object()->check_entry_room(x,y);
  if(file) {
    file->loadaus();
    room = find_object(file);
    if(room) {
      rooms += ([ (string) x+"_"+y : (object) room ]);
      return 1;
    }
    write("Failed to load.\n");
    return 0;
  }

  file = this_object()->query_room_file(msymbol);
  if(!file) return 0;
  room = clone_object(file);
  room->set_coordinates(x,y);
  room->set_mainfile(MAINFILE);
  rooms += ([ x+"_"+y : room ]);
  return 1;
}

/* return 1 if no_walk */
status check_no_walk(string msymbol) {
  int i;
  for(i=0; i < sizeof(no_walk); i++) {
    if(no_walk[i] == msymbol) return 1;
  }
  return 0;
}

void set_no_walk(string *str) {
  no_walk = str;
}

string get_map_color(string terrain) {
  switch(terrain) {
  case "f": return GREEN_F;
  case "~": return BLUE_F;
  case "r": return BLUE_F;
  case "F": return GREEN_F;
  case "p": return YELLOW_F ;
  case "s": return MAGENTA_F ;
  case "^": return RED_F;
  default: return "";

/*  case "h": return 0;
  case "H": return 0; */
  }
}

string get_map_char(int x, int y, int X, int Y, status big) {
  string msymbol;
  if(x<0 || y<0 || y>=sizeof(mapdata) || x>=strlen(mapdata[y])) return " ";
  if(x == X && y == Y) return "*";
  msymbol = mapdata[y][x..x];
  if(this_player()->query_terminal() && big) {
    msymbol = get_map_color(msymbol) + msymbol + OFF;
  }
  return msymbol;
}

int *get_minimap_x_size(int size) {
  switch(size) {
    case 1: return ({ 3, 1, });
    case 2: return ({ 7,5,5, });
    case 3: return ({ 11,11,9,5, });
    case 4: return ({ 15,15,15,13,9, });
    case 5: return ({ 19,19,19,17,13,7, });
    case 6: return ({ 23,23,23,21,19,15,9, });
    default: return ({ 29,29,29,29,23,17,13,7, });
  }
}

string generate_minimap(int x, int y, string ldesc, status big) {
  string terrain, *line, minimap, empty, d;
  int i, j, map_size, *x_length;

  minimap = "";
  empty = "                                                         ";
  map_size = this_object()->get_minimap_size(get_map_char(x,y,0,0,0));
  if(!map_size) map_size = DEFAULT_MINIMAP_SIZE;
  map_size -= 3 - this_player()->test_dark(1);
  if(big) map_size += 2;
  x_length = get_minimap_x_size(map_size);
  line = allocate(map_size*2+1);
  if(ldesc) {
    i = 2;
    while(i < 6 && ldesc && i < sizeof(line)) {
      if(sscanf(ldesc, "%s\n%s", line[i], ldesc) == 2) { }
      else if(sscanf(ldesc, "%s\n", line[i]) == 1) {
	ldesc = 0;
	line[i+1] = this_player()->test_dark(0,1);
      }
      i += 1;
    }
  }
  for(j = y + sizeof(x_length)-1; j > y - sizeof(x_length); j--) {
    terrain = "";
    for(i = x - x_length[abs(y - j)]/2 +1; i < x + x_length[abs(y - j)]/2; i++) {
	terrain += get_map_char(i,j,x,y,big);
    }
    if(j==y) terrain = " "+terrain;
    if(y != j)
      terrain = empty[0..(x_length[0] - x_length[abs(y - j)])/2] + terrain +
	empty[0..(x_length[0] - x_length[abs(y - j)])/2];
    else
	terrain += " ";
    d = line[ abs(y+map_size-1 - j) ];
    if(!d) d = ""; else d = "    " + d;
    minimap += terrain + d + "\n";
  }
  if(this_player()->query_terminal() && big)
	minimap += OFF;
  return minimap;
}

int abs(int i) {
  if(i < 0) return -i;
  else return i;
}

void set_special_mark(int x, int y, string mark) {
  string tmp;
  if(!mark) mark = "?";
  tmp = mapdata[y];
  tmp = tmp[0..x-1] + mark + tmp[x+1..strlen(tmp)];
  mapdata[y] = tmp;
}

/* defines mapdata, MAX_X, MAX_Y */
void set_mapfile(string file) {
  mixed heh;
  int i, line;
  string data, map;

  mapfile=file;
  map = "";
  /* read in small pieces for max_read_bytes is too small */
  while(data || !line) {
    data = read_file(file,line, 50);
    line += 50;
    map = map + data;
  }
  mapdata=explode(map, "\n");
  /* switch to 'normal' coords */
  mapdata=invert_rows(mapdata);
  heh=({ });
  /* drop out empty lines (strlen < 5) */
  for(i=0;i<sizeof(mapdata);i++) {
    if(strlen(mapdata[i])>4) heh+= ({ mapdata[i] });
  }
  mapdata=heh;
  MAX_X=strlen(mapdata[0]);
  MAX_Y=sizeof(mapdata); 
}

string *invert_rows(string *tmp) {
        int i;
        string *rv;
        rv=({ });
        for(i=sizeof(tmp);i--; ) {
                rv+=({ tmp[i] });
        }
        return rv;
}

string query_mapfile() {
        return mapfile;
}       

object query_room(int x, int y) {
  return rooms[x+"_"+y];
}
