inherit "obj/monster";
reset(arg) {
::reset(arg);
if(arg) { return; }
set_level(15);
set_name("bat");
set_short("A vampire bat");
set_long("You see a vampire bat hanging from caves ceiling.\n"+
"Bat is looking at you hungrily and it smells fresh blood from you,\n"+
"You discover some blood on bat's teeth..\n");
set_block_dir("up");    
set_al(-10);
set_aggressive(0); 
}       
