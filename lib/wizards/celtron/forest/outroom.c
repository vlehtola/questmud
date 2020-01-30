/* Change all the paths and filenames. */

string id;
int coordinate_x, coordinate_y;
string map;

set_coordinates(x,y) {
    coordinate_x = x;
    coordinate_y = y;
}

set_id(str) {
  id = str;
}

id(str) { return str == id; }

reset() {
  if(call_other(find_object("/wizards/celtron/forest/map"),"query_number")<250) {
    if(random(2) == 0) {
      move_object(clone_object("/wizards/celtron/forest/ugly_orc"), this_object());
    } else {
      move_object(clone_object("/wizards/celtron/forest/crow"), this_object());
    }
    call_other(find_object("/wizards/celtron/forest/map"), "add_number");
  }
}

init() {
    add_action("show_big_map", "map");
    add_action("south", "south");
    add_action("north", "north");
    add_action("east", "east");
    add_action("west", "west");
    add_action("northwest", "northwest");
    add_action("northeast", "northeast");
    add_action("southwest", "southwest");
    add_action("southeast", "southeast");
}

show_big_map() {
    write("You start looking around..\n");
    call_out("show_map", 1);
    return 1;
}

show_map() {

find_object("/wizards/celtron/forest/map")->draw_map(coordinate_x,coordinate_y,1);
}

north() {

if(!find_object("/wizards/celtron/forest/map")->move_living("north",coordinate_x,coordinate_y))
{
    return 0;
  }
  return 1;
}

south() {

if(!find_object("/wizards/celtron/forest/map")->move_living("south",coordinate_x,coordinate_y))
{
        return 0;
    }
    return 1;
}

east() {

if(!find_object("/wizards/celtron/forest/map")->move_living("east",coordinate_x,coordinate_y))
{
        return 0;
    }
    return 1;
}

west() {

if(!find_object("/wizards/celtron/forest/map")->move_living("west",coordinate_x,coordinate_y))
{
        return 0;
    }
    return 1;
}
northwest() {

if(!find_object("wizards/celtron/forest/map")->move_living("northwest",coordinate_x,coordinate_y))
{
        return 0;
    }
    return 1;
}

southeast() {

if(!find_object("/wizards/celtron/forest/map")->move_living("southeast",coordinate_x,coordinate_y))
{
        return 0;
    }
    return 1;
}

northeast() {

if(!find_object("/wizards/celtron/forest/map")->move_living("northeast",coordinate_x,coordinate_y))
{
    return 0;
  }
  return 1;
}

southwest() {

if(!find_object("/wizards/celtron/forest/map")->move_living("southwest",coordinate_x,coordinate_y))
{
    return 0;
  }
  return 1;
}

