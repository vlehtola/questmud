inherit "obj/weapon";
int i;

start() {
  set_class(7);
  set_sub_type("warhammer");
  set_alias("hammer");
  set_name("warhammer");
  set_short("A sharp-edged stone warhammer");
  set_long("Numerous sharp edges are the first particularly charasteristical signs of\n" +
           "this completely stony warhammer. The rough-cut edges all around the hammer\n" +
           "look dangerously lethal. The handle, which seems to be the only part of\n" +
           "the warhammer, which is not full of edges, is smoothly ground. The stone\n" +
           "warhammer looks quite heavy and always ready to deal damage and destruction.\n");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(7) != 0) return;
  i = random(75) + 76;
  tell_room(environment(wielded_by), "The stone warhammer rips " + wielded_by->query_attack()->query_name() + "'s skin open, causing blood to pour on the ground.\n");
  wielded_by->query_attack()->hit_with_spell(i);
  /*wielded_by->query_attack()->make_wound();*/
  return 1;
}
