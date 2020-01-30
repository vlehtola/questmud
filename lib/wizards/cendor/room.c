/*
 * This is a proposal of a replacement to std.h. It is used with
 * 'inherit "room/room";'.
 * All global variables below are supposed to be setup by the reset()
 * in the function that inherits this file.
 */

/* An array with destinations and directions: "room/church", "north" ... */
string dest_dir;

/* Short description of the room */
string short_desc;

/* Long description of the room */
string long_desc;

/* Special items in the room. "table", "A nice table", "window", "A window" */
string items;

/* Fact about this room. ex: "no_fight", "no_steal" */
string property;

/* No castles are allowed to be dropped here */
int no_castle_flag;

/* Blocker name and direction */
string blocker, direction;

/* direction possibly blocked by requirements */
string req;

/* Defines if sunlight affects this room: 0 = not affecting, 1 = affects */
int out;

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

query_dir(file) {
  int i;
  while(i<sizeof(dest_dir)) {
    if (dest_dir[i] == file) { return dest_dir[i+1]; }
    i += 2;
  }
}

id(str) {
    int i;
    if (!items)
	return;
    while(i < sizeof(items)) {
	if (items[i] == str)
	    return 1;
	i += 2;
    }
    return 0;
}

long(str) {
    int i, light_level;
    light_level = this_player()->test_dark();
    if (!str) {
	write(long_desc);
	if (!dest_dir)
	    write("    No obvious exits.\n");
	else {
	    i = 1;
	    if (sizeof(dest_dir) == 2)
		write("    There is one obvious exit:");
	    else
		write("    There are " + convert_number(sizeof(dest_dir)/2) +
		      " obvious exits:");
	    while(i < sizeof(dest_dir)) {
	      this_player()->lited(" "+dest_dir[i]);
		i += 2;
		if (i == sizeof(dest_dir) - 1)
		    write(" and");
		else if (i < sizeof(dest_dir))
		    write(",");
	    }
	    write("\n");
	}
	return;
    }
    if (!items)
	return;
    i = 0;
    while(i < sizeof(items)) {
	if (items[i] == str) {
	    write(items[i+1] + ".\n");
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
	    if (sscanf(dest_dir[i-1], "out: %d %d", x, y)) {
	        ob = find_object("world/out/map");
		ob->move_living(dest_dir[i], x, y);
		return 1;
	    }
            if (sscanf(dest_dir[i-1], "f_out: %d %d", x, y)) {
                ob = find_object("/wizards/celtron/forest/map");
                ob->move_living(dest_dir[i], x, y);
                return 1;
            }
	    this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
	    return 1;
	}
	i += 2;
    }
}

short(no_exits) {
  int i, light_level;
  string str, color;
  if (no_exits) { return short_desc; }
  light_level = this_player()->test_dark();
  if (light_level > 0) {
    str = " (";
    i = 1;
    while(i<sizeof(dest_dir)) {
      if (dest_dir[i] == "north") {
	str = str + sprintf("%c",27) + "[1;1;34mn"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "south") {
        str = str + sprintf("%c",27) + "[1;1;34ms"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "east") {
        str = str + sprintf("%c",27) + "[1;1;34me"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "west") {
        str = str + sprintf("%c",27) + "[1;1;34mw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "northwest") {
        str = str + sprintf("%c",27) + "[1;1;34mnw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "northeast") {
        str = str + sprintf("%c",27) + "[1;1;34mne"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "southwest") {
        str = str + sprintf("%c",27) + "[1;1;34msw"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "southeast") {
        str = str + sprintf("%c",27) + "[1;1;34mse"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "up") {
        str = str + sprintf("%c",27) + "[1;1;34mu"+sprintf("%c",27)+"[0m";
      }
      else if (dest_dir[i] == "down") {
        str = str + sprintf("%c",27) + "[1;1;34md"+sprintf("%c",27)+"[0m";
      }
      else {
        str = str + sprintf("%c",27) + "[1;1;34m"+dest_dir[i]+
	  sprintf("%c",27)+"[0m";
      }
      if(i+2<sizeof(dest_dir)) { str = str + ","; }
      i += 2;
    }
    str = str + ")";
    if (light_level == 1) {
	return "It is too dark to see " + str;
    }	
    return short_desc + str;
  }
  return "It is too dark to see";
}

query_not_out() {
    return out;
}

set_not_out(o) {
    out = o;
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

query_numbers() {
    if (!numbers) {
	if (file_name(this_object()) == "room/room")
	    numbers = ({"no", "one", "two", "three", "four", "five",
			    "six", "seven", "eight", "nine" });
	else
	    numbers = call_other("room/room", "query_numbers");
    }
    return numbers;
}

query_drop_castle() {
    return no_castle_flag;
}
