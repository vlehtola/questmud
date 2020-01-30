//A system for critical elemental spells -- Rag, 31.1.2004
//Returns the modified damage
//Max damage with normal crit +50%
//There is a small chance for a special crit which gives up to +300% dam

#define MASTERY_D "/daemons/mastery_d"

//After limit: int = limit+(int-limit)/2
#define INT_LIMIT 300
#define INT_MAX 3*INT_LIMIT

int spellcrit ( int dam, string type, object caster ) {

  int skill, inte, damage, mastery;
  string word;

  if ( !dam ) return 0;
  if ( !type || !caster ) return dam;

  damage = dam;
  skill = caster->query_skills("conjure elemental powers");
  inte = caster->query_int();

  if ( !skill ) return damage;

  //Different dam types
  switch (type) {
    case "physical":
      word = "Earth";
      break;
    case "fire":
      word = "Fire";
      break;
    case "cold":
      word = "Ice";
      break;
    case "electric":
      word = "Lightning";
      break;
    default:
      return damage;
      break;
  }

  mastery = MASTERY_D->query_mastery( "Dangerous "+word, caster );

  skill += mastery;

  //10% chance to get critical with max skill & mastery
  //5% max for monsters
  if ( skill < random(2000) ) {
    return dam;
  }

  if ( inte > INT_LIMIT ) {
    inte = INT_LIMIT + (inte-INT_LIMIT)/2;
  }
  if ( inte > INT_MAX ) {
    inte = INT_MAX;
  }

  skill += inte;

  //There should be about 10% chance to get the special crit
  //with nice int and maxed skill & mastery

  if ( skill < random(5000) ) {
    //T�h�n normikritti

  } else {

    //T�h�n �berdamage
  }

  return damage;
}
