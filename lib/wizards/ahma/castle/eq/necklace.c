inherit "obj/armour";
start() {
  set_value(2000);
  set_name("necklace");
  set_short("Necklace with fangs and grinning skull attached to it");
  set_long("In the durable-looking, metallic string is attached numerous fangs and a skull.\n" + 
           "You are not aware of which animals' fangs the ones hanging from the string are,\n" + 
           "but they are not too big. The fangs are shiny-white and sharp, almost perfectly\n" + 
           "shaped in any way, maybe they have been polished after being ripped off from\n" + 
           "their previous owner's mouth. The strange, grinning skull is in the middle of\n" + 
           "the necklace, surrounded by fangs. The skull is very small, only a bit bigger\n" + 
           "than the fangs. It has been carved empty, and glowing red pieces of stone have\n" + 
           "been stuffed in the previous eye holes. The necklace lets out annoying rattling\n" + 
           "noise when moved");
  set_slot("neck");
  set_stats("str", 1);
  set_stats("dex", 2);
  set_stats("con", 2);
}
