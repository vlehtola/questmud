inherit "room/room";

object money;

reset(arg) {
   int value;
   short_desc = "Rat's den";
   long_desc = "You are in a dirty hole. This must be the rat's den.\n"+
	"At least the smell would indicate that.\n";
   add_exit("east", "world/mine/rat_min5.c");

   money = clone_object("obj/new_money");
   value = random(3) + 1;
   money->set_value(value);
   money->set_type(4);
   move_object(money, this_object());
}
