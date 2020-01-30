/* Change all the paths and filenames. */

string id;
int coordinate_x, coordinate_y;
string short_desc, long_desc, mapfile;
int entrytime; // This is for possible cleanups. See init(). -Nalle

reset(arg) {
  if(arg) return;
  this_object()->start();
}
short() { return short_desc; }
long() {
  object ob;
  if (this_player()->query_wiz()) {
    write("Coordinates: " + coordinate_x + "," + coordinate_y + "\n");
  }
  ob = find_object(mapfile);
  if (!ob) {
    write("OBJECT NOT FOUND!\n");
    return 0;
  }
  ob->draw_map(coordinate_x,coordinate_y,0,long_desc);
  return 1;
}

set_coordinates(x,y) {
  coordinate_x = x;
  coordinate_y = y;
}

set_id(str) {
  id = str;
}

id(str) { return str == id; }

init() 
{
    entrytime = time(); // Time of last entry

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

move_me() {
  object ob;
  ob = find_object(mapfile);
  if(!ob) return 0;
  return ob->move_living(query_verb(),coordinate_x,coordinate_y);
}

show_map() {
  object ob;
  ob = find_object(mapfile);
  if(ob) ob->draw_map(coordinate_x, coordinate_y, 1);
}

int query_last_entry() { return entrytime; }
