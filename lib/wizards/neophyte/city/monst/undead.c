inherit "obj/monster";

reset(arg) {

    int i;
    ::reset(arg);
    if(arg) { return; }
    i = random(30);
    if(i>0) {

    set_level(20);
    set_name("undead");
    set_alias("ghost");
    set_short("A ghost of the lighthouse");
    set_long("The ghost belongs to a drowned sailor, he has wandered around the seas and\n"+
             "finally he found a place where to settle down, the lighthouse. The hair of\n"+
             "ghost is white and brittle, actually his whole body is white and brittle.\n");
    set_undead(1);
    set_aggressive(0);
    set_gender(1);
        }
    if(i>5) {

    set_level(30);
    set_name("undead");
    set_alias("spectre");
    set_short("A spectre of hideous pirate");
    set_long("Once, the spectre was a hideous pirate, who robbed and terrorized the trading\n"+
             "ships, which sailed around the seas trading stuff, unawared about the pirates.\n"+
             "For long time his life was perfect, he was rich and everybody scared him.\n"+
             "Some years ago a big storm raged and sunked his ship with whole crew with it.\n");
    set_undead(1);
    set_aggressive(0);
    set_gender(1);
      }


    if(i>15) {

    set_level(40);
    set_name("undead");
    set_alias("spirit");
    set_short("A spirit of ancient navigator");
    set_long("The navigators were the pioneers, predecessors of the sailing and the seas.\n"+
             "They gathered information to map making, to a handbook of navigation. But\n"+
             "often they suffered shipwrecks in their journeys and drowned.\n");
    set_undead(1);
    set_aggressive(1);
    set_gender(1);
      }

    if(i==0) {

    set_level(45);
    set_name("undead");
    set_alias("phantom");
    set_short("A phantom of sea captain, drowned with his sunken ship");
    set_long("In former times, the sea captain was one of the respected occupations. The\n"+
             "phantom belongs to an old sea captain, who drowned with his ship. The\n"+
             "phantom is enormous and strongest creature around, in the lighthouse.\n");
    set_undead(1);
    set_aggressive(1);
    set_gender(1);
 }
}
