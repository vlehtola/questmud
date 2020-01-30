inherit "obj/monster";
reset(arg) {
   ::reset(arg);

set_name("Wolf guard");
set_level(20);
set_alias("guards");
set_short("A guard stands here guarding something");
set_long("A tall man clad in wolf furs stands here seemingly guarding something.\n"+
	 "He is strongly built man with lots of muscle.\n");
set_aggressive(0);
set_block_dir("enter");
set_block_message("The guard says: 'You can go in the chamber of the king!'");
 
}
