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

if(!find_object("/wizards/celtron/forest/map")->move_living("southeast",coordinate_x,coordinate_y))
{
    return 0;
  }
  return 1;
}

