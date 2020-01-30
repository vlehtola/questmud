inherit "room/room";
inherit "room/door";
int stairs;
reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A corridor on the first floor of the lighthouse";
long_desc =  "A dark corridor inside the lighthouse, the walls and ceiling of the\n"+
             "corridor are black with dust. A fireplace built from red bricks is\n"+
             "on the back wall. Center of corridor is a fishing boxes that are going\n"+
             "all the way up to the ceiling. In here is quite strong smell of fishes\n"+
             "and smoke.\n";

  property = allocate(1);
  property[0] = "no_summon";
  door_reset();
  set_door_label("oak door",1);
  set_door_dir("east", "/wizards/neophyte/city/lighthouse/corridor6",1);
  set_door_link("/wizards/neophyte/city/lighthouse/corridor6",1);
  set_door_code(66, 1);
  set_locked(0, 1);
  }

init() {
  ::init();
  door_init();
}

search_finished(str) {
        if(stairs == 0 && str == "boxes") {
                write("You have found stairs going up!\n");
                say(this_player()->query_name()+ " founds stairs going up.\n");
                add_exit("up", "corridor8");
                stairs = 1;
                return 1;
        }
        write("You find nothing special.\n");
        say(this_player()->query_name()+ " founds nothing.\n");
        return 1;
}
