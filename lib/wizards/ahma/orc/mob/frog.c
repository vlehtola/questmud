inherit "obj/monster";
int i = random(4);

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level((3*i)+10);
  set_name("frog");
  set_alias("animal");
  set_alt_name("toad");
  if(i==0) { set_short("Tiny brown frog"); }
  if(i==1) { set_short("Small green frog"); }
  if(i==2) { set_short("Spotted brown frog"); }
  if(i==3) { set_short("Huge ugly river toad"); }
  if(i==0 || i=1 || i=2) {
    set_long("Quite small frog is sitting on the ground. Now and then it croaks\n" + 
             "and hops in the air, but mostly it seems just to stand still in one\n" + 
             "spot. The frog's skin is slimy, preventing it from drying out.\n");
  }
  if(i=3) {
    set_long("Amazingly big and ugly frog is glaring at you. Frog's chin is moving\n" + 
             "in and out from its mouth as it breathes lazily. The frog croaks now\n" + 
             "and then, but mostly it stays still. Frog's skin is slimy and a weak\n" + 
             "stench is spreading from the animal.\n");
  }
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Frog croaks noisily.\n";
    chat_str[1] = "Frog glares at you with its black eyes.\n";
    chat_str[2] = "Frog hops up and down in one spot.\n";
  }
  load_chat(3, chat_str);
  
  set_frog();
  set_animal();
}
