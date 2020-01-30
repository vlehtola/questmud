inherit "obj/weapon";


start() {
set_class(7);
set_sub_type("flail");
set_short("The black flail of the Guardian <demonic glow>");
set_long("Magnificent looking flail, it looks sturdy and the blade looks sharp enough\n" +
	 "to even slice through the hardest armour.\n");
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
if (random(5) == 1) {
  tell_room(environment(wielded_by), "The flail glows red, as it burns " +
  wielded_by->query_attack()->query_name()+"'s flesh!\n"); 
  wielded_by->query_attack()->hit_with_spell(wielded_by->query_level()/5,1) + random(wielded_by->query_level()/2);
  return 1; }	}
}                
