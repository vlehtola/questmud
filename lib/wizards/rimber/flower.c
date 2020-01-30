inherit "obj/armour";

start()
{
   set_class(1);
   set_name("flower");
   set_short("A small yellow flower");
   set_long("This is a beautiful yellow flower.\n"+
            "Flower is really beautiful and it is shining brightly as you watch it");
}


drop(arg)
{
  object ob;
  ob = environment(environment(this_object()));
  if(!ob->kissa_location()) return 0;

  tell_room(ob, "As you drop the flower a small man thunders in.\n");
  tell_room(ob, "Ikira screams: 'Hakitu akasiku harito!'\n");
  move_object(clone_object("/wizards/moonstar/areas/mosnotar/forest/monsut/ikira.c"), ob);
  call_out("delay_dest", 1, this_object());

}
int delay_dest(object ob) { destruct(ob); }
