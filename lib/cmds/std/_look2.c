/* look. recoded //Celtron */

#include <ansi.h>

#define MAX_LIST 30
#define STACK_D "/daemons/string_stack_d"
#define ENVIRONMENT_D "/cmds/std/_environment"

status not_living(object ob) {
  return !living(ob);
}

cmd_look2(string str,int brief, object player) {
  object *livings, *items, tp;
  string *items_str;

  string lista;
  int is_light, i;

  if(!player) {
    player = this_player();
  }
  tp = this_player();
  if (this_player()->query_uncon()) {
    tell_object(player, "You are unconcious and unable to see anything!\n");
    return 1;
  }
  is_light = this_player()->test_dark();
  if (is_light < 1) {
    return 1;
  }

  if(str) {
    return look_at(str,brief,tp, is_light);
  }

  /* missa asennosa aurinko jne on */
  display_time_of_day(tp);
  /* kuinka hyvin nakee + shortti ja longi  */
  display_darkness_level(tp, is_light, brief);

  /* erotellaan living objectit ja muut kamat */
  livings = filter(all_inventory(environment(tp)), #'living );
  items = filter(all_inventory(environment(tp)), "not_living");

  // Display livings
  for(i=0; i < sizeof(livings); i++) {
    if(livings[i] != tp && livings[i]->short() && !livings[i]->query_invisible()) {
      if (is_light == 1) { tell_object(tp, "Something living in the darkness.\n"); }
      else 
      {

	// Nallen enviv�rit
	if( !livings[i]->query_npc() )
	 tell_object(tp, get_env_color("players")+livings[i]->short()+OFF+"\n"); 
	else // -> is a monster
	{
	if( livings[i]->query_aggressive() )
	 tell_object(tp, get_env_color("aggressive_monsters")+
			livings[i]->short()+OFF+"\n"); 
	 else
	 tell_object(tp, get_env_color("monsters")+
			livings[i]->short()+OFF+"\n");
	}
	// ENDOF Nallen enviv�rit
      }
    }
  }

  /* stackataan ekut */
  items_str = allocate(sizeof(items));
  for(i=0; i < sizeof(items); i++) 
  {
    items_str[i] = items[i]->short();
  }
  lista = STACK_D->stack_item_list(items_str);
  if(lista)
    tell_object(player, lista+"\n");
  return 1;
}

/* Below code needs to be recoded */

look_at(string str,int brief,tp, int is_light) {
  object ob, ob_tmp, obje, kohde;
  string item,lista;
  int max, i,ii;
  if (sscanf(str, "at %s", item) == 1 || sscanf(str, "in %s", item) == 1) {
    int weight;
    if (is_light < 1) {
      tell_object(tp,"It is too dark to see.\n");
      return 1;
    }
    if (is_light < 3) {
      tell_object(tp,"It is too dark to see any details.\n");
      return 1;
    }
    item = lower_case(item);
    ob = present(item, this_player());
    if (!ob && call_other(environment(this_player()), "id", item))
      ob = environment(this_player());
    if (!ob)
      ob = present(item, environment(this_player()));
    if (!ob) {
      tell_object(tp,"You see nothing special.\n");
      return 1;
    }
    call_other(ob, "long", item);
    kohde = ob;
    weight = ob->query_weight()/100;
    if (!living(ob) && weight) tell_object(tp, "It looks "+get_weight_msg(weight)+".\n");
    if (!call_other(ob, "can_put_and_get", item)) return 1;
    item = ob;
    if (living(ob)) {
      object special;
      special = first_inventory(ob);
      while(special) {
        string extra_str;
        extra_str = call_other(special, "extra_look");
          if (extra_str)
            tell_object(tp,extra_str + ".\n");
          special = next_inventory(special);
      }
    }
    ob_tmp = first_inventory(ob);
    while(ob_tmp && call_other(ob_tmp, "short") == 0)
      ob_tmp = next_inventory(ob_tmp);
    max = MAX_LIST;
    ob = first_inventory(ob);
    while(ob && max > 0) {
      if (ob->query_worn() || ob->query_wielded()) {
        int don;
        string sh;
        sh = call_other(ob, "short", 0);
        if (sh) {
          if (ob->query_slot() && ob->query_slot() != "finger") {
            tell_object(tp,capitalize(ob->query_slot()) + ": " +
                        capitalize(sh) + ".\n");
          } else if (ob->query_slot() && !don) {
            tell_object(tp, "Fingers: some rings.\n");
            don = 1;
          }
        }
      }
      ob = next_inventory(ob);
      max -= 1;
    }
    if(living(item) && item->query_name()) {
      command("scan "+(lower_case(item->query_name())), this_player());
    }
    if(tp != kohde) {
      tell_room(environment(tp), tp->query_name()+" looks at "+kohde->short()+".\n", ({ tp, kohde, }));
      tell_object(kohde, tp->query_name()+" looks at you.\n");
    }
    /* SCAN RESISTS FOR MAGE UPTUNE //Celtron */
    if(kohde && living(kohde)) scan_res(kohde);
    return 1;
  }
  tell_object(tp,"Look AT something, or what?\n");
  return 1;
}

scan_res(object kohde) {
  string *skill, *resist, output;
  int i, sk, res;
  output = "";
  skill = ({"cast ice", "cast fire", "cast electric", });
  resist = ({ "cold", "fire", "electric", });
  for(i=0; i<sizeof(skill) ; i++) {
    sk = this_player()->query_skills(skill[i]);
    res = kohde->query_resists(resist[i]);
    if(sk) {
      if(sk - res < 0 && res < 50)
	output += "You are not skilled enough to see if "+kohde->query_pronoun()+" is resistant to "+resist[i]+".\n";
      else if(res < 40)
        output += capitalize(kohde->query_pronoun())+" looks vulnerable to "+resist[i]+".\n";
      else if(res < 70)
	output += capitalize(kohde->query_pronoun())+" looks resistant to "+resist[i]+".\n";
      else
	output += capitalize(kohde->query_pronoun())+" looks highly resistant if not invulnerable to "+resist[i]+".\n";
    }
  }
  write(output);
}

get_weight_msg(weight) {
  switch(weight) {
  case 0 .. 1 : return "extremely light";
  case 2 .. 3 : return "very light";
  case 4 .. 6 : return "reasonably light";
  case 7 .. 10 : return "quite heavy";
  case 11 .. 16 : return "heavy";
  case 17 .. 24 : return "very heavy";
  case 25 .. 50 : return "extremely heavy";
  case 51 .. 100 : return "unliftable";
  }
  return "unliftable";
}

display_darkness_level(tp, is_light, brief) {
  if (is_light < 2) {
    tell_object(tp,"It is so dark that you can't see clearly.\n");
    tell_object(tp, call_other(environment(tp), "short",0,tp) + ".\n");
    return 1;
  } else if (is_light == 2) {
    tell_object(tp,"It is so dark that you can't see clearly.\n");
    tell_object(tp, call_other(environment(tp), "short",0,tp) + ".\n");
    return 1;
  }
  if(brief) {
    if (environment(tp)->short())
      tell_object(tp, call_other(environment(tp),"short",0,tp)+"\n");
  } else {
    call_other(environment(tp), "long", 0,tp);
  }
}

display_time_of_day(tp) {
  int time_of_day;
  if (environment(tp) && !environment(tp)->query_not_out()) {
    time_of_day = find_object("obj/timer")->get_time_of_day();
  } else {
    return 1;
  }
  if (time_of_day == 2) {
    tell_object(tp,"It is evening and the sun is setting.\n");
  }
  if (time_of_day == 3) {
    tell_object(tp, "It is night and quite dark.\n");
  }
  if (time_of_day == 4) {
    tell_object(tp,"It is morning and the sun is rising.\n");
  }
}


/*************************/

get_env_color(string type)
{
 (object) (ENVIRONMENT_D);
 return ENVIRONMENT_D->give_color(this_player(), type);
}