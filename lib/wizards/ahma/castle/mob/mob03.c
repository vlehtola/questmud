inherit "obj/monster";

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(6)+18);
  set_name("demon");
  set_alias("dog");
  set_short("Horned dog-like demon");
  set_long("The dog-like creature is moving with its four feet. It looks a bit bigger\n" + 
           "than a normal dog, maybe a size of great winter wolf. The snout is similiar to\n" + 
           "the dog's muzzle, but in the mouth there seems to be three rows of extremely\n" + 
           "sharp teeth. This creature also seems to own quite long and sharp claws. The\n" + 
           "demon is covered in black fur. Somewhere the blood has made tufts in its ugly\n" + 
           "fur. The creature's animal instincts make it growl at you in the same time as\n" + 
           "pressing itself near the ground and wait for good moment to take action.\n");
  set_al(-40);
  set_aggressive(0);
  set_resists("fire",50);
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "The dog growls at you.\n";
    chat_str[1] = "The dog digs a corpse lying on the ground.\n";
    chat_str[2] = "The dog eyes you awaringly.\n";
  }
  load_chat(3, chat_str);  
}
