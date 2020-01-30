inherit "obj/armour"; 
 
start() {
set_class(1);
    set_slot("cloak");
    set_name("robes");
    set_alias("robes");
    set_short("Raistlin's velvet robes, decorated with yellow stars [wrapped in mystery]");
    set_long("These robes are made for raistlin to measure. The robes are made of velvet,"+
             " decorated with yellow stars. The stars are raistlin's own symbol, which"+
             " he wanted to add to the custom-made robes. The robes are seamless, therefore"+
             " it's long lasting and durable");
    set_stats("con", 3);
    set_stats("dex", -5);
    set_stats("int", 7);
    set_stats("spr", 7);
    set_value(2500);
    set_weight(500);
}
