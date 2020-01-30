inherit "obj/weapon";


start() {
set_class(7);
set_sub_type("flail");
set_short("The black flail of the Guardian <demonic glow>");
set_long("Magnificent looking flail, it looks sturdy and the blade looks sharp enough\n" +
	 "to even slice through the hardest armour.\n");
set_stats("str",10);
set_stats("con",10);
set_stats("dex",-10);
set_stats("wis",-10);
set_stats("int",-10);
set_stats("hit",10);
set_stats("dam",5);
}

hit() {
if(!wielded_by || !wielded_by->query_attack()) return;
if(wielded_by->query_alignment() > 1 ) {
write("The flail burns YOUR hands!\n");
wielded_by->hit_with_spell(50) + random(50);
return 1;
}
if(wielded_by->query_attack()->query_alignment() > 1 ) {
  tell_room(environment(wielded_by), "The flail glows red, as it burns " +
  wielded_by->query_attack()->query_name()+"'s flesh!\n"); 
  wielded_by->query_attack()->hit_with_spell(50) + random(50);
  return 1; }
}                
