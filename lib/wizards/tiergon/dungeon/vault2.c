inherit "room/room";
inherit "room/door";
object money;

reset(arg) {
int value;
set_not_out(1);
set_door_dir("out","/wizards/tiergon/dungeon/vault1");
set_door_link("/wizards/tiergon/dungeon/vault1");
set_door_desc("massive vault ");
short_desc = "Inside the vault";
  long_desc = "This is where the supervisor kept the cash used to pay the miners.\n"+
                "Looks like this room hasn't been reached by the attackers\n";
money = clone_object("obj/money");
value = random (400) + 1;
money->set_value(value);
money->set_type(3);
move_object(money, this_object());
}

init() {
  ::init();
  door_init();
}
