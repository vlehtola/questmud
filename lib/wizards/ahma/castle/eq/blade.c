inherit "obj/weapon";

start() {
  set_class(6);
  set_sub_type("short sword");
  set_name("blade");
  set_short("Sparkling crystal blade");
  set_long("The blade is made of finest and most fragile crystal you have ever seen. The\n" + 
           "blade is surrounded by a strong blue aura, giving you the feeling that when\n" + 
           "used, the weapon will be very effective. Commonly, crystal swords are highly\n" + 
           "respected for their beauty and effectiveness. Most of the crystal swords are\n" + 
           "also very durable, but this one really does not look like one of them. The\n" + 
           "blade trembles softly all the time you hold it in your hands, and small pulses\n" + 
           "of some unknown energy can be seen flowing inside the blade in very thin vein-\n" + 
           "like channels. The surroundings of the blade feel warm and quiet humming can\n" + 
           "be heard inside the blade when concentrating hard.\n");
}

hit() {
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(2) == 0) { 
  tell_room(environment(wielded_by), "The crystal blade cracks and breaks.\n");
  destruct(this_object());
  return 1;
  }
  else {
  tell_room(environment(wielded_by), "The crystal blade hits " + wielded_by->query_attack()->query_name() + " with bright blue explosion of light.\n");
  wielded_by->query_attack()->hit_with_spell(30000+random(10000));
  tell_room(environment(wielded_by), "The crystal blade shatters into million pieces.\n");
  destruct(this_object());
  return 1;
  }
}