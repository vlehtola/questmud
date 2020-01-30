inherit "obj/monster";
int i = random(2);

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+(i*3)+25);
  set_name("mountain wolf");
  set_alt_name("wolf");
  set_alias("animal");
  if(!i) {set_short("A gray mountain wolf"); } else { set_short("A silvery mountain wolf"); }
  set_long("A large-sized mountain wolf is looking for something to hunt down.\n" + 
           "Wolf's hair is silvery gray, but some dust stain it. Wolf seems to\n" + 
           "favor other of its back legs, maybe it has injured it somewhere in\n" + 
           "the woods or mountains. From wolf's eyes can be seen that its inner\n" + 
           "flame is burning strong.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Wolf licks its left back leg.\n";
    chat_str[1] = "Wolf growls softly at you.\n";
    chat_str[2] = "Wolf sits on the ground but soon stands up again.\n";
  }
  load_chat(3, chat_str);
  
  set_animal();
  set_al(10);
}
