inherit "obj/armour";
start() {
  set_value(200);
  set_name("cloak");
  set_short("Black cloak of Shadows");
  set_long("The jet black cloak seems to suck the light around it, making the cloak being\n" + 
           "surrounded with black aura all the time. The nearings of the cloak feel also\n" + 
           "somewhat cold. The legend tells about a cloak which made its wearer almost\n" + 
           "invisible in the darkness of a night. It was used among many thieves last\n" + 
           "century, but then it was lost with one apprentice thief, who left to accomplish\n" + 
           "a thieving task but never came back. The cloak is otherwise deep black, but\n" + 
           "a violet line can be spotted surrounding the borders of the cloak. The cloak\n" + 
           "can be attached to a torso armour with an ordinary chain mechanism");
  set_slot("cloak");
  set_stats("str", -2);
  set_stats("dex", 10);
  set_stats("con", 5);
  set_resists("fire", 15);
  set_resists("electric", 15);
}
