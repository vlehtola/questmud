inherit "obj/weapon";
start() {
  set_class(3);
  set_sub_type("maul");
  set_slayer("elf");
  set_short("Dark vibrating Maul)";
  set_long("This is the maul used by Morfeus. It vibrates continously. This Maul can\n"
	   "do some serious damage if used correctly.\n");
 
hit() {
if(!wielded_by || !wielded_by->query_attack()) return;
if(random(5)) return;
tell_room(environment(wielded_by), "Mace SWINGS itself and "
        "MUTILATES "+wielded_by->query_attack()->query_name()+"!\n");
wielded_by->query_attack()->hit_with_spell(random(50)+50,0);
  return 1;
}

}
