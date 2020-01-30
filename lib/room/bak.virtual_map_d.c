#include <ansi.h>

/* final version of virtual map daemon //Celtron */

/* optimizations to the map colouring code by Nalle 210404 */

#define MAINFILE        file_name(this_object())
#define AREA_D          "/daemons/area_d"
#define DEFAULT_MINIMAP_SIZE    3

static int MAX_Y, MAX_X;
static string *no_walk;         /*  '*' stands for allocate */
static mapping rooms;           /* loaded rooms, objects. room = rooms[x+"_"+y] */
static string *mapdata;         /* actual map data, allocs in alloc */
static string mapfile;          /* datafile. txt map */

// Prototypes

string *invert_rows(string *tmp);
string fast_map_char(int x, int y, int X, int Y, status big, string prev_char);
string get_map_char(int x, int y, int X, int Y, status big);
status check_no_walk(string msymbol);
status generate_room(int x, int y, string msymbol);
int abs(int i);
object get_room(string dir, string dest, int x, int y);

// Code

void destruct_loaded_room(int x, int y) 
{
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
  rooms += ([ "load": this_object() ]);
  write("room/virtual_map_d.c loaded.\n");
}

/* called when moving on vmap */
void move_living(object walker, string arg, int x, int y) {
  int ep_cost, hiking, i;
  object room, tmp_room, p_ob, *ob;
  object horde_ob;

  room = get_room(arg,0,x,y);
  if(!room) return;

  if(x && y) 
    {
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
  if((!p_ob || this_player() == p_ob->query_leader()) || environment(p_ob->query_leader()) != room ) 
    {
    tmp_room = (object) MAINFILE->room_loaded(room,x,y, get_map_char(x,y,0,-1,0));

      if(tmp_room && objectp(tmp_room) && !this_player()->query_invisibility_level()) 
	{
         room = tmp_room;
   
         // By Nalle 010203 - Take hordes to ambush
         horde_ob=present("horde_summon",this_player());
         if(horde_ob)  
	   {
	    horde_ob->teleport_horde_free();  
	   }
   
	 /* partytapauksessa hela party lentaa ambushiin */
         if(p_ob) 
	   {
            ob = all_inventory(environment(this_player()) );
            for(i=0; i < sizeof(ob); i++) 
		{
                if(ob[i] && p_ob->is_member(ob[i])) move_object(ob[i], room);
		}
	   }
       }
    } 
  /* endof Ambush code */

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
      rooms += ([ (string) x+"_"+y : room ]);
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

void set_no_walk(string *str) { no_walk = str; }

string get_map_color(string terrain) {
  switch(terrain) {
  // There are some 2002 additions, not all are fully implemented
  case "f": 
  case "F": return GREEN_F;

  case "p": return YELLOW_F;

  case "~": 
  case "r": return BLUE_F;


  case "h":
  case "C": return CYAN_F;

  case "H": return MAGENTA_F;
  case "s": return RED_F;
  case "^": 
  case "|": 
  case "-": 
  case "+": //return sprintf("%c",27)+"[1;1;30m";
  case "/": 
  case "\\": return sprintf("%c",27)+"[1;1;30m";

  default: return "";
  }
}

/*
 * Added the 'prev_char' variable, so that successive mapchars
 * will no longer be coloured :  YELLOW + "p" + OFF + YELLOW + "p" + OFF
 * 		          but :	 YELLOW + "pp" + OFF
 * This should significanty reduce CPU and bandwith usage.
 * 
 * - Nalle 21 April '04
 */

// Produces same effect as old get_map_char
string get_map_char(int x, int y, int X, int Y, status big)
{
 return fast_map_char(x, y, X, Y, big, "slow");
}

string fast_map_char(int x, int y, int X, int Y, status big, string prev_char) 
{
 string msymbol;

 if(x<0 || y<0 || y>=sizeof(mapdata) || x>=strlen(mapdata[y])) return " ";

  if(x == X && y == Y) 
    {
     if (this_player()->query_terminal() && big) 
        return OFF+BOLD+"*"+OFF;
	 else
    	return "*";
    }

  msymbol = mapdata[y][x..x];

  if(!prev_char) prev_char = "";

  if(this_player()->query_terminal() && big) 
  {
   // Prev char of "slow" forces the old cumbersome output. Do not use.
   if( prev_char == "slow" )
      return get_map_color(msymbol) + msymbol + OFF;

   // This is the speedup shit.
   if( prev_char != msymbol || ( x == X+1 && y == Y+1) )
     //msymbol = OFF + get_map_color(msymbol) + "S" + msymbol;
     msymbol = OFF + get_map_color(msymbol) + msymbol;
  }

  return msymbol;
}

int *get_minimap_x_size(int size) 
{
  switch(size) 
	{
    	 case 1:  // return ({ 4,3,3, });
    	 case 2:  return ({ 5,5,5, });
    	 case 3:  return ({ 8,8,6,2, });
    	 case 4:  return ({ 12,12,12,10,6, });
    	 case 5:  return ({ 16,16,16,14,10,4, });
    	 case 6:  return ({ 20,20,20,18,16,12,6, });
    	 default: return ({ 25,25,25,25,19,15,11,4, });
  	}
}

string generate_minimap(int x, int y, string ldesc, status big, object obj) 
{
  string terrain, *line, minimap, empty, d;
  int i, j, map_size, *x_length;
  object ob;

  if(obj)
    {
     ob = obj;
    } 
     else 
    {
     ob = this_player();
    }

  minimap = "";
  empty = "                                                         ";

  map_size = this_object()->get_minimap_size(get_map_char(x,y,0,0,0));
  if(!map_size) map_size = DEFAULT_MINIMAP_SIZE;
  map_size -= 3 - ob->test_dark(1);

   if(big) 
     { 
      map_size += 2;
      ldesc = 0; // Disable long desc if big map -N
     }
 
  x_length = get_minimap_x_size(map_size);
  line = allocate(map_size*2+1);

  if(ldesc) 
  {
    i = 2;
    while(i < 6 && ldesc && i < sizeof(line)) 
     {
      if(sscanf(ldesc, "%s\n%s", line[i], ldesc) == 2) { }
         else
	if(sscanf(ldesc, "%s\n", line[i]) == 1) 
	  {
           ldesc = 0;
           line[i+1] = ob->test_dark(0,1);
          }
      i++;
     }
  }

 for(j = y + sizeof(x_length)-1; j > y - sizeof(x_length); j--) 
  {
   terrain = "";

    for (i = x - x_length[abs(y - j)]/2 +1; i < x + x_length[abs(y - j)]/2; i++)
	{
	 if(strlen(terrain) > 1)
         terrain   += fast_map_char(i, j, x, y, 1, terrain[strlen(terrain)-1..strlen(terrain)-1]);
	  else
         terrain   += fast_map_char(i, j, x, y, 1, "");
	}

    if(j==y) terrain = " "+terrain;
    if(y != j)
      terrain = empty[0..(x_length[0] - x_length[abs(y - j)])/2] + terrain +
        empty[0..(x_length[0] - x_length[abs(y - j)])/2];
    else
        terrain += " ";

    d = line[ abs(y+map_size-1 - j) ];

    if(!d) 
	 d = ""; 
	else 
	{
	 if(this_player()->query_terminal())
	    d = OFF + "    " + d;
	      else
	    d = "    " + d;
	}

    minimap += terrain + d + "\n";
  }

  if(ob->query_terminal()) minimap += OFF;
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

// be careful if calling this
string *query_mapdata() { return mapdata; }

string query_mapfile() { return mapfile; }

object query_room(int x, int y) {
  return rooms[x+"_"+y];
}
