typedef struct {
	char *qtext, *qtext2, *ans[4];
} Question;

#define NUM_OF_QUESTIONS 30

Question questions[NUM_OF_QUESTIONS] = {
	{ .qtext = "Quelle ville n'est pas", .qtext2 = "en Belgique ?", .ans = { "Lyon", "Gent", "Anvers", "Bruxelles" } },
	{ .qtext = "Quelle est le mot belge", .qtext2 = "pour \"d�ner\" ?", .ans = { "souper", "d�jeuner", "lunch", "petit d�jeuner" } },
	{ .qtext = "Quel pays ne fait pas partie", .qtext2 = "de Francophonie ?", .ans = { "le Br�sil", "la Suisse", "le Canada", "le Monaco" } },
	{ .qtext = "La capitale du Luxembourg est ...", .qtext2 = "", .ans = { "Luxembourg", "Bern", "Zurich", "Austerlitz" } },
	{ .qtext = "La capitale du Canada est ...", .qtext2 = "", .ans = { "Ottawa", "Toronto", "Vancouver", "Qu�bec" } },
	{ .qtext = "Dans quel pays on dit septante,", .qtext2 = "huitante et nonante (70, 80 et 90) ?", .ans = { "Suisse", "Canada", "Maroc", "Belgique" } },
	{ .qtext = "Combien de gens qui parlent", .qtext2 = "fran�ais y a-t-il dans le monde ?", .ans = { "~250 millions", "~600 millions", "~87 millions", "~120 millions" } },
	{ .qtext = "La capitale de la Suisse est ...", .qtext2 = "", .ans = { "Bern", "Zurich", "Lucerne", "Gen�ve" } },
	{ .qtext = "Quel pays est connu", .qtext2 = "pour le chocolat ?", .ans = { "la Suisse", "le Madagascar", "la France", "l'Andorre" } },
	{ .qtext = "Qu'est-ce que c'est", .qtext2 = "le DROM, COM ?", .ans = { "des r�gions fran�aises", "des �les fran�aises", "les colonies en Afrique", "la monnaie en Afrique" } },
	{ .qtext = "La Polyn�sie fran�aise", .qtext2 = "est dans l'oc�an...", .ans = { "Pacifique", "Indien", "Atlantique", "Austral" } },
	{ .qtext = "Combien de r�gions", .qtext2 = "y a-t-il en France ?", .ans = { "13", "22", "5", "21" } },
	{ .qtext = "Qu'est-ce que c'est un cr�ole ?", .qtext2 = "", .ans = { "une langue simplifi�e", "un type de g�teau", "une �le fran�aise", "un village indig�ne" } },
	{ .qtext = "Quelles sont les couleurs", .qtext2 = "du drapeau de la Belgique ?", .ans = { "jaune, noir, rouge", "noir, blanc, rose", "bleu, blanc, rose", "vert, rouge, noir" } },
	{ .qtext = "Combien de r�gions", .qtext2 = "y a-t-il en Belgique ?", .ans = { "3", "10", "8", "13" } },

	{ .qtext = "La plupart des Fran�ais sont ...", .qtext2 = "", .ans = { "chr�tiens", "bouddhistes", "ath�es", "musulmans" } },
	{ .qtext = "Carl Gustav Jung a �t� ...", .qtext2 = "", .ans = { "suisse", "allemand", "fran�ais", "belge" } },
	{ .qtext = "Quel pays est connu", .qtext2 = "pour le sirop d'�rable ?", .ans = { "le Canada", "la Suisse", "la France", "la Belgique" } },
	{ .qtext = "Quelles sont les langues", .qtext2 = "officielles au Canada ?", .ans = { "anglais, fran�ais", "anglais, fran�ais, cr�ole", "inuit, fran�ais, italien", "fran�ais, allemande" } },
	{ .qtext = "Combien de gens � Monaco", .qtext2 = "sont millionnaires ?", .ans = { "30 %", "20 %", "40 %", "10 %" } },
	{ .qtext = "Le Luxembourg est ...", .qtext2 = "", .ans = { "un grand-duch�", "une principaut�", "une federation", "une r�publique" } },
	{ .qtext = "Stocafi est un plat national de...", .qtext2 = "", .ans = { "Monaco", "le Luxembourg", "la Belgique", "la Suisse" } },
	{ .qtext = "Qui est \"le p�re", .qtext2 = "de la francophonie\" ?", .ans = { "L�opold S�dar Senghor", "Ren� Maran", "Jean-Paul Belmondo", "Michel Lentz" } },
	{ .qtext = "Quelle mati�re premi�re est", .qtext2 = "la plus export�e du Maghreb ?", .ans = { "le p�trole", "du caf�", "les diamants", "du th�" } },
	{ .qtext = "Quelle langue n'est pas", .qtext2 = "officielle en Suisse ?", .ans = { "anglais", "italien", "romanche", "allemande" } },
	{ .qtext = "Quel pays utilise l'euro ?", .qtext2 = "", .ans = { "Monaco", "la Suisse", "le Canada", "le Maroc" } },
	{ .qtext = "Quelle monnaie est utilis�e", .qtext2 = "aux DROM, COM ?", .ans = { "euro", "franc", "dollar", "couronne" } },
	{ .qtext = "Quelle �le se trouve entre", .qtext2 = "l'Afrique et le Madagascar ?", .ans = { "Mayotte", "Nouvelle Cal�donie", "Polyn�sie fran�aise", "Guyane fran�aise" } },
	{ .qtext = "Combien de pays y a-t-il", .qtext2 = "dans DROM, COM ?", .ans = { "10", "17", "7", "20" } },
	{ .qtext = "Quelles deux religion y a-t-il", .qtext2 = "en Afrique de nord ?", .ans = { "christianisme et islam", "islam et bouddhisme", "christianisme et bouddhisme", "islam et hinduisme" } },
};
