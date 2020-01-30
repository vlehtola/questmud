inherit "obj/armour";

start() {
set_class(3);
    set_slot("cloak");
    set_name("cloak");
    set_short("Cloak of the Forest Ranger (composing)");
    set_long("This cloak is very old and brittle as thin ice. The cloak has been made of\n"+ 
             "composing materials. You have to be very careful with handling this cloak.\n"+
             "A big tree with massive branches has been sewed in the back of the cloak");
    set_stats("con", 4);
    set_stats("str", 7);
    set_stats("dex", 4);
    set_resists("cold", 5);
    set_value(3500);
    set_weight(200);
}


drop(arg) {

  object ob;

  ob = find_object("/wizards/irmeli/bwp/room24");

  if(!ob || environment(environment(this_object())) != ob) {

    return 0;

  }



  tell_room(ob, "An ugly woman rushes from a thick bush and grabs the cloak!\n");

  move_object(clone_object("/wizards/irmeli/bwp/monsters/witch"), ob);

  this_player()->set_quest("Lure the witch out from the bushes");

  destruct(this_object());

  return 1;

}
