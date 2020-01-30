/* Change all the paths and filenames. */

static int x,y;
static string short_desc, long_desc, mainfile;

string query_mainfile() {
  return mainfile;
}

int query_x() {
  return x;
}

int query_y() {
  return y;
}

void set_coordinates(int i, int j) {
  x = i; y = j;
}

void reset(status arg) {
  if(arg) return;
  this_object()->start();
}

void set_mainfile(string str) {
  mainfile = str;
}

string short() { return short_desc; }

string query_long() { return long_desc; }

void long(mixed str, object obj) {
  object ob;
  if(obj) {
  	ob = obj;
  } else {
  	ob = this_player();
  }
  if (ob->query_wiz()) {
    write("Coords: " + x + "," + y + " Mainfile: "+mainfile+"\n");
  }
  write(mainfile->generate_minimap(x,y,long_desc,0,ob));
}

void init() {
    add_action("show_big_map", "map");
    add_action("move_me", "south");
    add_action("move_me", "north");
    add_action("move_me", "east");
    add_action("move_me", "west");
    add_action("move_me", "northwest");
    add_action("move_me", "northeast");
    add_action("move_me", "southwest");
    add_action("move_me", "southeast");
}

show_big_map() {
    write("You start looking around..\n");
    call_out("show_map", 1);
    return 1;
}

status move_me() {
/* move_living(object walker, string arg, int x, int y) */
  mainfile->move_living(this_player(), query_verb(), x, y);
  return 1;
}

void show_map() {
/* generate_minimap(int x, int y, string ldesc, status big) */
  write("\n"+mainfile->generate_minimap(x,y,long_desc,1));
}


