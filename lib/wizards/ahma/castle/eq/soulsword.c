inherit "obj/weapon";
int i, h;

start() {
  set_class(9);
  set_sub_type("broad sword");
  set_name("sword");
  set_short("Demonic broad sword named 'Soul Stealer'");
  set_long("Extremely long and sharp looking great sword. You have not seen a sword like\n" +
           "this in quite a while. The edge of the sword is made from some metal unknown\n" +
           "to you. It is very sharp and durable, and yet, light. Edge shines its soft\n" +
           "reddish glow, and seems that when blood is poured on the sword, it is sucked\n" +
           "somewhere inside the blade. The sword feels very comfortable and a bit warm\n" +
           "when wielded. This sword must be made by demons, though you have heard some\n" +
           "stories about an ancient life-sucking sword among humans. The story tells that\n" +
           "somewhere within the demon territories, there is a sword which is capable of\n" +
           "sucking its master's enemies' life out from their bodies, and give it to its\n" +
           "master. The sword is called the Soul Stealer due to its strange draining capability.\n");
  set_stats("str", 10);
  set_stats("dex", 10);
  set_stats("con", 10);
}

hit() {
  i = (random(45)+100);
  if(!wielded_by || !wielded_by->query_attack()) return;
  if(random(3) != 0) return 1; {
  tell_room(environment(wielded_by), "The red aura around Soul Stealer starts to glow brighter.\n");
  if(random(2) != 0) return 1; {
  tell_object(wielded_by, "Bright red light shoots out from the Soul Stealer as it drains " + wielded_by->query_attack()->query_name() + "'s health to you.\n");
  say("Bright red light shoots out from the Soul Stealer as it drains " + wielded_by->query_attack()->query_name() + "'s health to its master.\n", wielded_by);
  wielded_by->query_attack()->hit_with_spell(i, "physical");
  wielded_by->add_hp(i/4); wielded_by->add_ep(i/10);
  return 1;
  }
  }
}
