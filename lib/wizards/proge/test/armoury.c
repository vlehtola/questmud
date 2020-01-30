/* 
Armoury, where player's can order eqs with
customized stats. 

++ Proge (Jan 2003)

*/

inherit "room/room";

object item;
string eqfile; /* string that is written to file */
int i;
string *attribs;
int status_busy;
string filename;
string filu;

reset(arg)
{
  if(arg) return;
  status_busy = 0;
  add_exit("west", "/wizards/proge/lab");
  short_desc = "Armoury of Duranghom";
  long_desc = "This is the Armoury of Duranghom. Adventurers come long\n"+
    "to get a weapon made by the famous weapon and armour smiths\n"+
    "of this place. There is some polished and shining weapons\n"+
    "and shields hanging in the walls. You can see see a full plate\n"+
    "mail armour in the corner and a plaque hanging on the wall\n"+
    "Maybe you should 'look at plaque'.\n";
}


init()
{
  add_action("order", "order");
  add_action("look", "look");
  ::init();
}


look(str)
{
  if (str == "at plaque")
    {
      write("Currently available:\n"+
            "----------------------------\n"+
            "|*'                      '*|\n"+
            "|'   1. broad sword       '|\n"+
            "|    1. great axe          |\n"+
            "|    2. maul               |\n"+
            "|    4. large shield       |\n"+
            "|                          |\n"+
            "|    5. great helm         |\n"+
            "|    6. chain gauntlets    |\n"+
            "|    7. arm guards         |\n"+
            "|    8. boots              |\n"+
            "|    9. leggings           |\n"+
            "|'  10. plate mail        '|\n"+
            "|*'                      '*|\n"+
            "----------------------------\n"+
            "'order <nmbr> <class> [str,con,dex,int.wis] [1-9] ...'\n");
      return 1;
    }
  return;
}

/* this one makes a custom weapon. it creates a file
   customeq_[i].c where [i] is the number of the weapon ordered */

order(str) {
  if(status_busy == 1) 
    {
      say("We are currently busy with the previous orders.\n");
      return 1;
    }
  attribs = explode(str, " ");
  for(i = 1; i < sizeof(attribs); i += 2)
    {
      if(to_int(attribs[i]) < 0)
        {
          attribs[i] = "0";
        }
      if(to_int(attribs[i]) > 9)
        {
          attribs[i] = "20";
        }
    }
  if (to_int(attribs[0]) >=1 && to_int(attribs[0]) >= 4)
    {
      
      eqfile = 
        "/* AUTOMATICALLY GENERATED EQ-FILE.\n"+
        "!!! DO NOT REMOVE UNLESS YOU KNOW WHAT YOU'RE DOING !!! */\n\n"+
        "inherit \"obj/weapon\";\n\n"+
        "start() {\n\n";

    } else if(to_int(attribs[0]) >= 5 && to_int(attribs[0]) <= 10)
      {

        eqfile =
          "/* AUTOMATICALLY GENERATED EQ-FILE.\n"+
          "!!! DO NOT REMOVE UNLESS YOU KNOW WHAT YOU'RE DOING !!! */\n\n"+
          "inherit \"obj/armour\";\n\n"+
          " start() {\n\n";

      } else
        {
          if(this_player()->query_wiz() >= 1)
            {
              write("! wrong kind of type or sumthing.\n");
            }
          write("Order WHAT?\n");
          return 1;
        }
  switch(to_int(attribs[i]))
    {
    case 1 :
      eqfile += "   set_sub_type(\"broad sword\");\n";
      eqfile += "   set_short(\"Custom made broad sword of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted broad sword with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
      break;
    case 2 :
      eqfile += "   set_sub_type(\"great axe\");\n";
      eqfile += "   set_short(\"Custom made great axe of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted great axe with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
      break;
    case 3 :
      eqfile += "   set_sub_type(\"maul\");\n";
      eqfile += "   set_short(\"Custom made maul of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted maul with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
      break;
    case 4 :
      eqfile += "   set_sub_type(\"large shield\");\n";
      eqfile += "   set_short(\"Custom made large shield of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted large shield with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
      break;
    case 5 :
      eqfile += "   set_sub_type(\"great helm\");\n";
      eqfile += "   set_short(\"Custom made great helm of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted great helm with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
     break;
    case 6 :
      eqfile += "   set_sub_type(\"chain gauntlets\");\n";
      eqfile += "   set_short(\"Custom made chain gauntlets of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"These are fine, beautifully crafted chain gauntlets with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in them. They're shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in them.\\n\");\n";
      break;
    case 7 :
      eqfile += "   set_sub_type(\"arm guards\");\n";
      eqfile += "   set_short(\"Custom made arm guards of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"These are fine, beautifully crafted arm guards with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in them. They're shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in them.\\n\");\n";
      break;
    case 8 :
      eqfile += "   set_sub_type(\"boots\");\n";
      eqfile += "   set_short(\"Custom made boots of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"These are fine, beautifully crafted boots with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in them. They're shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in them.\\n\");\n";
      break;
    case 9 :
      eqfile += "   set_sub_type(\"leggings\");\n";
      eqfile += "   set_short(\"Custom made leggings of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"These are fine, beautifully crafted leggings with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in them. They're shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in them.\\n\");\n";
      break;
    case 10 :
      eqfile += "   set_sub_type(\"plate mail\");\n";
      eqfile += "   set_short(\"Custom made plate mail of "+this_player()+query_name()+"\");\n";
      eqfile += "   set_long(\"This is a fine, beautifully crafted plate mail with\\n\"+\n";
      eqfile += "            \"carvings of Armoury of Duranghom in it. Its shining as new.\\n\"+\n";
      eqfile += "            \"There must be some magic in it.\\n\");\n";
      break;
    default :
      write("There was a problem with your order.\n"+
            "You better contact the wizards.\n");
      break;
    }
  
  eqfile += 
    "   set_class(" + to_int(attribs[1]) + ");\n";
  
  for(i = 2; i < sizeof(attribs); i += 2)
    {
      switch(attribs[i])
        {
        case "str" :
          eqfile += "   set_stats(\"str\"," + to_int(attribs[i+1]) + ");\n";
          break;
        case "wis" :
          eqfile += "   set_stats(\"wis\"," + to_int(attribs[i+1]) + ");\n";
          break;
        case "con" :
          eqfile += "   set_stats(\"con\"," + to_int(attribs[i+1]) + ");\n";
          break;
        case "dex" :
          eqfile += "   set_stats(\"dex\"," + to_int(attribs[i+1]) + ");\n";
          break;
        case "int" :
          eqfile += "   set_stats(\"int\"," + to_int(attribs[i+1]) + ");\n";
          break;
        default :
          if(this_player()->query_wiz() >= 1)
            {
              write("! wrong kind of stats or sumthing.\n");
            }
          write("Order WHAT?\n");
          return 1;
          break;
        }
    }
  eqfile += " }\n}\n\nEOF";
  status_busy = 1;
  int randomi;
  randomi = random(3600)+2000;
  filu = ""+implode(explode(implode(explode(ctime(time()+randomi), " "), ""), ":"), "")+"";
  filename = "/wizards/proge/armoury/equipments/eq_type_"+attribs[0]+"_ordered_by_"+this_player()->query_name()+"_at_"+filu+".c";
  if(!write_file(filename, eqfile))
    {
      write("There was error with your order.\n"+
            "Error number: 1\n"+
            "Please contact the wizards.\n");
      return 1;
    }
  status_busy = 1;
  say("We'll start working on your order.\n"+
      "Come check later on if we're done.\n");
  if(!write_file("/wizards/proge/armoury/naulakko", ""+this_player()->query_name()+" "+filename))
    {
      write("There was a problem with your order.\n"+
            "Error number: 2\n"+
            "Please contact the wizards.\n");
      return 1;
    }
  call_out("valmista", 3500+1000);
  return 1;
}


valmis()
{
  say("We are done with the previous customer's order.\n");
  status_busy = 0;  
}




