/* players can learn skills by using them. anyhow they must be in combat to do so.
     //Celtron 
*/

// 5000*value^2 = actual_bonus
int skill_value(string skill, mapping learn_map, object player) {
  int value;

/* Joku kusee! t:N */
  if(!sizeof(learn_map)) return 0;
/* Kuseekohan viel�? */

  value = learn_map[skill];
  if(!value) return 0;
  value = to_int(sqrt(to_float(value) / 5000));
  return value;
}

// player tries to learn a skill
mapping learn_skill(string skill, mapping learn_map, object player, object prev_ob) {
  int value;
  if(!player || !prev_ob || !objectp(prev_ob) || !player->query_attacker() || file_name(prev_ob)[0..5] == "/cmds/")
        return learn_map;
  value = skill_value(skill, learn_map, 0);
  learn_map[skill] += 1;
  if(value != skill_value(skill, learn_map, 0)) {
    tell_object(player, "You learn new things and improve in '"+skill+"'.\n");
    log_file("LEARN", ctime(time())+" "+player->query_name()+", skill: "+skill+" (+"+skill_value(skill, learn_map, 0)+")\n");
  }
  return learn_map;
}

