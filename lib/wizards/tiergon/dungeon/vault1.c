inherit "room/room";
inherit "room/door";
object monster;

reset(arg) {
 if(!monster) {
    monster = clone_object("/wizards/tiergon/dungeon/monsters/specminer");
    move_object(monster, this_object()); }
  if(arg) return;
set_not_out(1);
add_exit("east","/wizards/tiergon/dungeon/top2");
door_reset();
set_door_dir("vault","/wizards/tiergon/dungeon/vault2");
set_door_link("/wizards/tiergon/dungeon/vault2");
random_door_code();
set_door_label("massive vault",1); 
short_desc = "Guard room";
 long_desc = "This room was once a guard room for protecting the vault.\n"+
             "There is a rusty plaque attached to the worn stone wall.\n";
items = allocate(4);
items[0] = "plaque";
items[1] = "You can just make out the words 'Faithful Beyond Death'";
}

init() {
  ::init();
  door_init();
}
