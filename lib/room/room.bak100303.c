/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */

/* An array with destinations and directions: "room/church", "north" ... */
static string dest_dir;

/* Short description of the room */
static string short_desc;

/* Long description of the room */
static string long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
string items;

/* Fact about this room. ex: "no_fight", "no_steal" */
string property;

/* No castles are allowed to be dropped here */
int no_castle_flag;

/* Blocker name and direction */
static string blocker, direction;

/* direction possibly blocked by requirements */
string req, map_exit_dir;

/* Defines if sunlight affects this room: 0 = not affecting, 1 = affects */
int out;
/* Define how much water in the room: Scale is 0 to 10 */
int water;

PATH() {
  return query_room_path();
}

query_room_path() {
  string path, tmp;
  tmp = explode(file_name(this_object()), "/");
  tmp[sizeof(tmp)-1] = "";
  path = "/"+implode(tmp, "/");
  return path;
}

init() {
    int i;
    if (!dest_dir)
	return;
    i = 1;
    while(i < sizeof(dest_dir)) {
	add_action("move", dest_dir[i]);
	i += 2;
    }
}

string parse_dir(string dir, status test) {
  string new_dir, *dir_, tmp;
  int back_dir, i;
  if(dir[0..6] == "virtual") return dir;
  if(dir[0..2] == "out") return dir;
  while(sscanf(dir, "%s//%s", tmp, dir)) {
    back_dir += 1;
  }
  if(!back_dir) {
    if(dir[0..0] == "/" || dir[0..7] == "wizards/" || dir[0..4] == "room/" || dir[0..5] == "world/")
	return dir;
    else
	return query_room_path() + dir;

  }
  dir_ = explode((string) query_room_path(), "/");
  if(back_dir > sizeof(dir_))
	return "error! no such back dir";
  new_dir = "";
  for(i=0; i < sizeof(dir_) - back_dir; i++) {
    new_dir += dir_[i]+"/";
  }
  new_dir += dir;
  if(new_dir[0..0] != "/") new_dir = "/"+new_dir;
  return new_dir;
}

add_exit(string dir, string dest) {
  int i,error;
  string tmp,kapy;
  object stuff;
  tmp = dest_dir;
  dest_dir = allocate(sizeof(tmp)+2);
  while(i<sizeof(tmp)) {
    if(tmp[i] == dir) error = 1;
    dest_dir[i] = tmp[i];
    i+= 1;
  }
  if(error) { dest_dir = tmp; return; }
  dest = parse_dir(dest);
  dest_dir[i] = dest;
  dest_dir[i+1] = dir;
  i = 0;
    kapy = "/obj/update_dest";
    stuff = all_inventory(this_object());
    while(stuff && i<sizeof(stuff)) {
        if(!stuff[i]->query_npc() && living(stuff[i])) {
          move_object(stuff[i],kapy);
        }
        i += 1;
    }
    i = 0;
    while(stuff && i<sizeof(stuff)) {
        if(stuff[i]) { move_object(stuff[i],this_object()); }
        i += 1;
    }
}

/* recode by Celtron */
remove_exit(string dir_str) {
  int i;
  string tmp;
  if (!dest_dir || !sizeof(dest_dir)) { return 0; }
  for(i=0; i < sizeof(dest_dir); i++) {
    if(dest_dir[i] == dir_str) {
      dest_dir[i] = 0;
      dest_dir[i-1] = 0;
      dest_dir = explode(implode(dest_dir, ","), ",");
      if(sizeof(dest_dir) == 1) dest_dir = 0;
      return 1;
    }
  }
  /* no such exit */
  return 0;
}

query_dir(string file) {
  int i;
  while(i<sizeof(dest_dir)) {
    if (dest_dir[i] == file) { return dest_dir[i+1]; }
    i += 2;
  }
}

id(str) {
    int i;
    if (this_object()->door_long_desc(str)) {
      return 1;
    }
    if (!items)
      return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}

long(str, object ob) {
    int i, light_level;
    light_level = this_player()->test_dark();
    if (!ob) { ob = this_player(); }
    if (!str) {
        if(long_desc) tell_object(ob,long_desc);
	this_object()->write_door_shorts();
	i = 0;
	if (!dest_dir || !sizeof(dest_dir) || !dest_dir[0])
	    tell_object(ob,"    No obvious exits.\n");
	else {
	    i = 1;
	    if (sizeof(dest_dir) == 2)
		tell_object(ob,"    There is one obvious exit:");
	    else
		tell_object(ob,"    There are " + convert_number(sizeof(dest_dir)/2) +
		      " obvious exits:");
	    while(i < sizeof(dest_dir)) {
	      ob->lited(" "+dest_dir[i]);
		i += 2;
		if (i == sizeof(dest_dir) - 1)
		    tell_object(ob, " and");
		else if (i < sizeof(dest_dir))
		    tell_object(ob, ",");
	    }
	    tell_object(ob, "\n");
	}
	return;
    }
    if (!items)
	return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
	    tell_object(ob, items[i+1] + ".\n");
	    return;
	}
	i += 2;
    }
}

/*
 * Does this room has a special property ?
 * The 'property' variable can be both a string and array of strings.
 * If no argument is given, return the 'property' variable.
 */
query_property(str) {
    int i;
    if (str == 0)
	return property;
    if (!property)
	return 0;
    if (stringp(property))
	return str == property;
    while(i < sizeof(property)) {
	if (property[i] == str)
	    return 1;
	i += 1;
    }
    return 0;
}
set_req(str) {
  req = str;
}

set_blocker(blocker_name, dir) {
    blocker = blocker_name;
    direction = dir;
}

move(str) {
    int i, x, y;
    object ob;
    i = 1;
    while(i < sizeof(dest_dir)) {
	if (query_verb() == dest_dir[i]) {
	    if (blocker) {
		if (present(blocker) && dest_dir[i] == direction) {
		     write(capitalize(blocker) + " blocks your way.\n");
		     return 1;
		}
	    }
	    if (req && dest_dir[i]==req&&this_object()->query_req()) { return 1; }

	    if (sscanf(dest_dir[i-1], "outmap: %d %d", x, y)) {
		this_player()->move_player(dest_dir[i]+"#virtual /room/out/outmap "+x+" "+y);
		return 1;
	    }
	    if (sscanf(dest_dir[i-1], "out: %d %d", x, y)) {
		  y = 199 - y; /* koordit v��rinp�in */
		  this_player()->move_player(dest_dir[i]+"#virtual /room/out/outmap "+x+" "+y);
		  return 1;
	        ob = find_object("world/out/map");
		ob->move_living(dest_dir[i], x, y);
		return 1;
	    }
            if (sscanf(dest_dir[i-1], "%s: %d %d", map_exit_dir, x, y)) {
                ob = find_object(map_exit_dir);
		if (!ob) { write("Map object not found.\n"); return; }
                ob->move_living(dest_dir[i], x, y);
                return 1;
            }
	    this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
	    return 1;
	}
	i += 2;
    }
}

short(no_exits, object ob) {
  int i, light_level;
  string str, color;
  if (no_exits) { return short_desc; }
  if (!ob) { ob = this_player(); }
  light_level = ob->test_dark();
  if (light_level > 0) {
    str = " (";
    i = 1;
    while(i<sizeof(dest_dir)) {
      if (dest_dir[i] == "north") {
	str = str + sprintf("%c",27) + "[1;1;36mn"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "south") {
        str = str + sprintf("%c",27) + "[1;1;36ms"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "east") {
        str = str + sprintf("%c",27) + "[1;1;36me"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "west") {
        str = str + sprintf("%c",27) + "[1;1;36mw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "northwest") {
        str = str + sprintf("%c",27) + "[1;1;36mnw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "northeast") {
        str = str + sprintf("%c",27) + "[1;1;36mne"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "southwest") {
        str = str + sprintf("%c",27) + "[1;1;36msw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "southeast") {
        str = str + sprintf("%c",27) + "[1;1;36mse"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "up") {
        str = str + sprintf("%c",27) + "[1;1;36mu"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "down") {
        str = str + sprintf("%c",27) + "[1;1;36md"+sprintf("%c",27)+"[0m";
      }
      else {
        str = str + sprintf("%c",27) + "[1;1;36m"+dest_dir[i]+
	  sprintf("%c",27)+"[0m";
      }
      if(i+2<sizeof(dest_dir)) { str = str + ","; }
      i += 2;
    }
    str = str + ")";
    if (light_level == 1) {
	return "A dark place" + str;
    }	
    return short_desc + str;
  }
  return;
}

query_not_out() {
    return out;
}

set_not_out(o) {
    out = o;
}

set_no_reloc() {
    property = "no_summon";
}
query_valid_dir(string dir) {
  int i;
  i = 1;
  while(i<sizeof(dest_dir)) {
    if (dest_dir[i] == dir) { return dest_dir[i-1]; }
    i += 2;
  }
}
query_dest_dir() {
    return dest_dir;
}

query_long() {
    return long_desc;
}

/*
 * Convert a number to a word. The array is being created by the
 * standard room/room, and shared by all rooms.
 */
string numbers;

convert_number(n) {
    if (!pointerp(numbers))
	numbers = query_numbers();
    if (n > 9)
	return "lot of";
    return numbers[n];
}

query_numbers(status original) {
    if (!numbers) {
	if (original)
	    numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	else
	    numbers = call_other("room/room", "query_numbers", 1);
    }
    return numbers;
}

query_drop_castle() {
    return no_castle_flag;
}

query_room_file() { return 1; }
int query_water() { return water; }
void set_water(int i) {
  water = i;
}

set_short(s) {
  short_desc = s;
}
set_items(s) {
  items = s;
}
set_property(s) {
  property = s;
}
set_long(s) {
  long_desc = s;
}

