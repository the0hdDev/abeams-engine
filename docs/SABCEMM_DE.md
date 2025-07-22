# SABCEMM: Ein Simulator für Agenten-basierte Wirtschaftsmarktmodelle – Eine detaillierte Analyse

## 1. Einleitung: Zweck und Motivation des SABCEMM-Simulators

Die Finanzmärkte sind komplexe Systeme, deren Dynamik oft schwer zu fassen ist. Insbesondere nach globalen Finanzkrisen hat das Interesse an neuen Modellierungsansätzen stark zugenommen, um die zugrundeliegenden Mechanismen besser zu verstehen.[^1] In diesem Kontext hat sich das Forschungsfeld der Ökonophysik, das Methoden der Physik auf ökonomische Phänomene anwendet, in den letzten zwei Jahrzehnten rasant entwickelt. Ein zentraler Bestandteil dieses Feldes sind Agenten-basierte Wirtschaftsmarktmodelle (ABCEM-Modelle), die künstliche Märkte mit interagierenden Akteuren simulieren, um reale Marktphänomene nachzubilden und zu analysieren.[^1]

### Hintergrund und Bedeutung von Agenten-basierten Wirtschaftsmarktmodellen (ABCEM)

ABCEM-Modelle stellen eine Abkehr von traditionellen ökonomischen Theorien dar, die oft auf der Effizienten Markthypothese (EMH) basieren. Die EMH geht davon aus, dass alle verfügbaren Informationen sofort in den Preisen widergespiegelt werden und Märkte stets im Gleichgewicht sind.[^1] Diese Hypothese steht jedoch umfangreicher Kritik gegenüber, da sie bestimmte Marktunregelmäßigkeiten, sogenannte "stilisierte Fakten", nicht erklären kann.[^1] Im Gegensatz dazu integrieren ABCEM-Modelle Verhaltensaspekte, psychologische Fehleinschätzungen von Agenten oder Lernmechanismen, um ein realistischeres Bild der Marktdynamik zu zeichnen.[^1] Die Agenten in diesen Modellen werden nicht als "homo oeconomicus" – rationale Nutzenmaximierer – konzipiert, sondern als "bounded rational agents" im Sinne von Herbert Simon. Das bedeutet, sie treffen Entscheidungen auf der Grundlage von Heuristiken und Verhaltensregeln, die oft psychologische Aspekte beinhalten.[^1] Ihr primäres Ziel ist es, Finanzdaten, die diese stilisierten Fakten aufweisen, zu replizieren und die Ursachen für deren Auftreten zu identifizieren, um so das Entstehen von Finanzkrisen besser zu verstehen.[^1]

#### Herausforderungen in der ABCEM-Forschung

Trotz des wachsenden Interesses und des Potenzials von ABCEM-Modellen standen Forscher vor erheblichen Herausforderungen. Ein wesentliches Problem war der Mangel an vereinheitlichten Modellen und Perspektiven. Da Modelle oft in unterschiedlichen Programmiersprachen implementiert und auf verschiedenen Systemen simuliert wurden, war ein objektiver Vergleich kaum möglich.[^1] Dies führte zu einer Fragmentierung der Forschung und erschwerte die Konsolidierung von Erkenntnissen.

Ein weiteres gravierendes Problem war die Schwierigkeit bei der Reproduzierbarkeit von Ergebnissen. ABCEM-Modelle sind typischerweise nicht-lineare dynamische Systeme, die sehr empfindlich auf kleine Parameteränderungen reagieren. Ihre starke Abhängigkeit von Pseudozufallszahlen bedeutet, dass eine exakte Reproduktion veröffentlichter Ergebnisse praktisch unmöglich ist. Zudem fehlten in vielen Publikationen oft vollständige Implementierungsdetails oder genaue Initialwerte, was die Nachvollziehbarkeit zusätzlich erschwerte.[^1]

Darüber hinaus gab es Bedenken hinsichtlich der Gültigkeit der in diesen Modellen beobachteten "stilisierten Fakten". Frühere Studien zeigten, dass viele dieser Phänomene lediglich numerische Artefakte sein könnten, insbesondere aufgrund von "finite size effects". Diese Effekte treten auf, wenn die Anzahl der simulierten Agenten qualitative Unterschiede in den Modellergebnissen verursacht. Um zuverlässige Ergebnisse zu erzielen und solche Artefakte zu vermeiden, sind Simulationen mit einer sehr großen Anzahl von Agenten erforderlich, was wiederum hohe Rechenressourcen bindet.[^1] Die geringe Konvergenzrate von Monte-Carlo-Simulationen, die für die Analyse dieser Modelle unerlässlich sind, verstärkt diesen Bedarf an umfangreichen Rechenläufen.[^1]

### Die Rolle und die Hauptziele des SABCEMM-Simulators

Die genannten Herausforderungen führten zur Entwicklung von SABCEMM (Simulator for Agent-Based Computational Economic Market Models). Dieses Simulationswerkzeug wurde konzipiert, um eine vereinheitlichte und effiziente Plattform für die ABCEM-Forschung zu bieten.[^1]

Ein Hauptziel von SABCEMM ist die Bereitstellung eines vereinheitlichten Simulationswerkzeugs, das eine breite Palette von ABCEM-Modellen in einer gemeinsamen Umgebung simulieren und vergleichen kann.[^1] Dies adressiert direkt das Problem der mangelnden Vergleichbarkeit und fördert eine kohärentere Forschung.

Das objektorientierte Design der Software, implementiert in C++, ermöglicht eine erhebliche Reduzierung des Programmieraufwands. Benutzer können neue Modelle einfach implementieren und testen, indem sie bestehende Bausteine wie Agententypen und Marktmechanismen über XML-Konfigurationsdateien rekombinieren.[^1] Dies beschleunigt den Modellentwicklungsprozess und senkt die Eintrittsbarriere für Forscher.

Die Effizienz für Großskalensimulationen ist ein weiteres Kernmerkmal. SABCEMM ist darauf ausgelegt, Modelle mit mehreren Millionen Agenten effizient auszuführen.[^1] Diese Fähigkeit ist entscheidend, um "finite size effects" zu analysieren und zu vermeiden sowie robuste Sensitivitätsanalysen durchzuführen, die für die Validierung der Modelle unerlässlich sind.

Schließlich fördert SABCEMM die Reproduzierbarkeit und Vergleichbarkeit von Forschungsergebnissen. Durch die Veröffentlichung des Codes und der Dokumentation auf GitHub sowie die Bereitstellung einer gemeinsamen Plattform mit verschiedenen Zufallszahlengeneratoren wird die Transparenz in der ABCEM-Forschung erheblich verbessert.[^1] Die Möglichkeit, alle Ergebnisse zu reproduzieren, ist ein Eckpfeiler wissenschaftlicher Integrität und ermöglicht es der Forschungsgemeinschaft, auf bestehenden Erkenntnissen aufzubauen.

Die Entwicklung von SABCEMM kann als eine Reaktion auf eine Reifekrise in der Ökonophysik verstanden werden. Das Feld hat in den letzten zwei Jahrzehnten erheblich an Dynamik gewonnen, was durch ein gestiegenes Interesse und eine wachsende Forschungsgemeinschaft belegt wird.[^1] Gleichzeitig traten grundlegende Probleme wie mangelnde Reproduzierbarkeit, Schwierigkeiten beim Modellvergleich aufgrund heterogener Implementierungen und das Auftreten numerischer Artefakte auf.[^1] Diese Herausforderungen sind charakteristisch für ein junges, sich schnell entwickelndes Forschungsgebiet, dem es noch an standardisierten Werkzeugen und Methoden mangelt. Sie behindern den wissenschaftlichen Fortschritt, da die Validierung und der Aufbau auf vorhandenen Ergebnissen erschwert werden. SABCEMM ist daher nicht nur ein technisches Werkzeug, sondern eine kritische Infrastruktur, die darauf abzielt, diese Phase zu überwinden, indem sie eine vereinheitlichte, effiziente und transparente Plattform bereitstellt. Der Fokus verschiebt sich von der reinen Modellentwicklung hin zu Validierung, Vergleichbarkeit und Skalierbarkeit, was für die Etablierung der Ökonophysik als robuste wissenschaftliche Disziplin von grundlegender Bedeutung ist.

Die Open-Source-Veröffentlichung von SABCEMM ist hierbei von strategischer Bedeutung für die wissenschaftliche Glaubwürdigkeit und die Bildung einer Gemeinschaft. Das Problem der Reproduzierbarkeit in ABCEM-Modellen ist gravierend, teilweise bedingt durch die Abhängigkeit von Pseudozufallszahlen und unvollständige Implementierungsdetails in Publikationen.[^1] Die Entscheidung, SABCEMM unter einer Open-Source-Lizenz auf GitHub zu veröffentlichen und alle Beispiele reproduzierbar zu machen, ist eine direkte Antwort auf dieses Problem.[^1] Dies ermöglicht es anderen Forschern, den Code zu prüfen, zu modifizieren und zu erweitern, was die Transparenz und damit die wissenschaftliche Glaubwürdigkeit der mit SABCEMM erzielten Ergebnisse erheblich steigert. Es ermöglicht eine Art Peer-Review auf Code-Ebene, ein Aspekt, der in der Simulationsforschung oft übersehen wird. Darüber hinaus ermutigen die Entwickler aktiv andere, ihre ABCEM-Modelle in den Simulator zu implementieren.[^1] Dies deutet auf das Bestreben hin, eine Gemeinschaft um das Werkzeug aufzubauen. Eine gemeinsame Codebasis und Plattform kann den Austausch fördern, zur Standardisierung beitragen und die kollaborative Weiterentwicklung des Feldes vorantreiben, wodurch die bisherige Fragmentierung der Forschung überwunden werden kann. Die Open-Source-Strategie ist somit nicht nur eine technische, sondern eine strategische Entscheidung zur Förderung wissenschaftlicher Exzellenz, Kollaboration und zur Etablierung bewährter Praktiken in der Ökonophysik.

---

## 2. Grundlagen der Agenten-basierten Wirtschaftsmarktmodelle (ABCEM)

Agenten-basierte Wirtschaftsmarktmodelle (ABCEM) stellen einen innovativen Ansatz zur Untersuchung von Finanzmärkten dar, der sich von traditionellen ökonomischen Theorien abhebt. Sie bieten eine alternative Perspektive, indem sie die komplexen Interaktionen zwischen individuellen Akteuren in den Vordergrund stellen, anstatt von idealisierten Gleichgewichtszuständen auszugehen.

### Was sind ABCEM-Modelle?

ABCEM-Modelle sind im Kern künstliche Märkte, die aus einer Vielzahl interagierender Agenten bestehen.[^1] Diese Modelle werden typischerweise mit Monte-Carlo-Simulationen analysiert, um die emergenten Phänomene des Marktes zu beobachten.[^1] Sie sind ein zentrales Forschungsfeld der Ökonophysik und haben in den letzten zwei Jahrzehnten, insbesondere nach den jüngsten Finanzkrisen, erheblich an Bedeutung gewonnen.[^1] Das Hauptziel dieser Modelle ist es, reale Finanzdaten, die bestimmte statistische Muster – sogenannte "stilisierte Fakten" – aufweisen, zu replizieren. Durch die Reproduktion dieser Fakten versuchen die Modelle, die zugrundeliegenden Ursachen für deren Auftreten zu identifizieren und somit ein tieferes Verständnis für die Entstehung von Finanzkrisen zu entwickeln.[^1]

### Stilisierte Fakten

Stilisierte Fakten sind empirische Beobachtungen in Finanzdaten, die sich über verschiedene Zeitskalen und in unterschiedlichen Aktienmärkten weltweit konsistent dokumentieren lassen.[^1] Sie repräsentieren robuste statistische Muster, die in realen Märkten immer wieder auftreten. Ein bekanntes Beispiel ist die Ungleichheit von Einkommen und Vermögen, die bereits 1897 von Vilfredo Pareto identifiziert wurde.[^1] Weitere wichtige Beispiele, die von Benoît Mandelbrot 1963 erkannt wurden, sind "Heavy Tails" (fette Enden) in Aktienrenditeverteilungen, was bedeutet, dass extreme Preisbewegungen häufiger vorkommen als von einer Normalverteilung vorhergesagt, sowie "Volatilitätsclustering", bei dem Perioden hoher Volatilität von Perioden niedriger Volatilität abgelöst werden.[^1]

Diese stilisierten Fakten spielen eine entscheidende Rolle bei der Entstehung von Finanzkrisen, und die Untersuchung ihrer Ursprünge ist von großer Bedeutung.[^1] ABCEM-Modelle legen nahe, dass stilisierte Fakten nicht notwendigerweise aus rationalem Verhalten resultieren, sondern durch Verhaltensaspekte, psychologische Fehleinschätzungen von Agenten oder Lernmechanismen entstehen können.[^1] Trotz ihrer Fähigkeit, diese Muster zu reproduzieren, wird kritisiert, dass ABCEM-Modelle nur ein begrenztes Bild der Realität zeichnen. Eine Erklärung von stilisierten Fakten in einem spezifischen Modell muss nicht unbedingt in einem anderen Modell Gültigkeit besitzen.[^1] Zudem haben frühere Studien gezeigt, dass einige der in Modellen beobachteten stilisierten Fakten lediglich numerische Artefakte sein können, insbesondere aufgrund von "finite size effects", bei denen die Anzahl der Agenten die Modellergebnisse qualitativ beeinflusst.[^1] Dies unterstreicht die Notwendigkeit, ABCEM-Modelle mit einer großen Anzahl von Agenten zu simulieren, um zuverlässige Ergebnisse zu gewährleisten.[^1]

### Abgrenzung zu klassischen Finanzmarktmodellen

Die Abgrenzung von ABCEM-Modellen zu klassischen Finanzmarktmodellen ist fundamental und betrifft mehrere Kernannahmen:

- **Effiziente Markthypothese (EMH) vs. Verhaltensökonomie:** Klassische Modelle basieren oft auf der EMH, die von rationalen Akteuren und effizienter Informationsverarbeitung ausgeht.[^1] ABCEM-Modelle hingegen sind stark von der Verhaltensfinanzierung beeinflusst und integrieren psychologische Aspekte in die Investitionsentscheidung.[^1]
- **Homo Oeconomicus vs. Bounded Rationality:** Während klassische Modelle den "homo oeconomicus" als rationalen Nutzenmaximierer annehmen[^1], modellieren ABCEM-Modelle Investoren als "bounded rational agents" im Sinne von Simon.[^1] Diese Agenten lösen keine komplexen Optimierungsprobleme, sondern treffen Entscheidungen auf der Grundlage von Heuristiken oder zufriedenstellenden Regeln, die oft erstaunlich gute Annäherungen an reale Investitionsprozesse darstellen.[^1]
- **Allgemeines Gleichgewicht vs. Disequilibrium:** Die klassische Wirtschaftstheorie, insbesondere die allgemeine Gleichgewichtstheorie, die auf Ökonomen wie Léon Walras zurückgeht, geht davon aus, dass Angebot und Nachfrage im Gleichgewicht übereinstimmen und ein "Auktionator" den Preis in einem "Tâtonnement"-Prozess findet.[^1] Dies setzt perfekte Information und keine Transaktionskosten voraus.[^1] ABCEM-Modelle hingegen verwenden oft einen "irrationalen Marktmechanismus" und das Konzept von Marktpreisen im Ungleichgewicht, bei dem die Preisanpassungsgeschwindigkeit endlich ist und beobachtete Preise nicht notwendigerweise Gleichgewichtspreisen entsprechen.[^1]

Die Entwicklung von ABCEM-Modellen stellt eine Verschiebung des Paradigmas von normativer zu deskriptiver Modellierung in der Finanzökonomie dar. Klassische Finanzmarktmodelle, die auf der EMH und dem "homo oeconomicus"-Paradigma basieren, sind oft normativ; sie beschreiben, wie Märkte sein sollten, wenn alle Akteure perfekt rational handeln.[^1] Die Unfähigkeit dieser Modelle, reale Marktphänomene wie stilisierte Fakten zu erklären, führte zu einer Lücke in der Modellierung.[^1] ABCEM-Modelle füllen diese Lücke, indem sie einen deskriptiveren Ansatz wählen. Sie versuchen zu verstehen, wie Märkte tatsächlich funktionieren, indem sie realistischere (wenn auch vereinfachte) Agentenverhaltensweisen und Interaktionen abbilden.[^1] Dies ist ein fundamentaler Wandel in der Finanzmodellierung. Anstatt idealisierte, oft nicht-empirisch beobachtbare Annahmen zu treffen, konzentriert sich ABCEM auf die Emergenz komplexer Makrophänomene aus einfachen Mikroregeln. Dies ist besonders relevant für das Verständnis von Marktinstabilitäten und Krisen, die in rein rationalen Gleichgewichtsmodellen schwer zu erfassen sind. Somit sind ABCEM-Modelle ein Werkzeug für eine realistischere und empirisch relevantere Finanzökonomie, die die Grenzen der traditionellen normativen Ansätze überwindet.

Die Herausforderung der Validierung von ABCEM-Modellen besteht trotz ihrer Fähigkeit, stilisierte Fakten zu reproduzieren. Während die Replikation stilisierter Fakten ein Hauptziel von ABCEM-Modellen ist, um deren Ursachen zu entdecken[^1], wird kritisiert, dass "eine Erklärung von stilisierten Fakten in einem Modell nicht notwendigerweise in einem anderen Modell zutrifft" und dass Ergebnisse "nur numerische Artefakte" sein könnten, insbesondere aufgrund von "finite size effects".[^1] Dies bedeutet, dass die Reproduktion stilisierter Fakten zwar ein notwendiges, aber kein hinreichendes Kriterium für die Validität eines ABCEM-Modells ist. Wenn verschiedene Modelle, die auf unterschiedlichen Annahmen basieren, dieselben stilisierten Fakten reproduzieren können, stellt sich die Frage nach der Kausalität und der Generalisierbarkeit der Erklärungen. Numerische Artefakte verschärfen dieses Problem, da sie fälschlicherweise als reale Phänomene interpretiert werden könnten. Dies unterstreicht die Notwendigkeit robuster Validierungsmethoden, die über die bloße Reproduktion von Mustern hinausgehen. Es erfordert systematische Sensitivitätsanalysen, den Vergleich von Modellen unter standardisierten Bedingungen (was SABCEMM ermöglicht) und möglicherweise die Entwicklung neuer statistischer Tests, um echte emergente Phänomene von numerischen Artefakten zu unterscheiden. Die Herausforderung liegt darin, von der "Mustererkennung" zur "Ursachenerklärung" überzugehen und sicherzustellen, dass die Modelle nicht nur die Symptome, sondern die zugrundeliegenden Mechanismen der Marktphänomene korrekt abbilden. SABCEMM ist hier ein wichtiger Schritt, indem es die technische Basis für solche rigorosen Validierungen schafft.

---

## 3. Das Abstrakte ABCEM-Modell: Die Bausteine

Der SABCEMM-Simulator basiert auf einem abstrakten Meta-Modell, das es ermöglicht, eine breite Palette von ABCEM-Modellen zu kategorisieren und zu implementieren. Dieses Meta-Modell zerlegt die komplexen Marktprozesse in drei grundlegende Bausteine: Agenten, Marktmechanismen und die Umgebung.

### 3.1 Agenten-Design

Das Herzstück jedes ABCEM-Modells sind die Agenten, die die individuellen Marktteilnehmer repräsentieren. Ein Agent wird durch drei zentrale Aspekte definiert[^1]:

1. **Individuelle Informationen:** Dies ist eine Sammlung von Daten, die für jeden Agenten einzigartig sind. Diese Informationen werden vom Agenten selbst gehalten, aktualisiert und in seinem Investitionsentscheidungsprozess verwendet. Beispiele hierfür sind die individuelle Meinung eines Agenten über den Marktzustand, die Historie seiner früheren Investitionsentscheidungen oder die Entwicklung seines persönlichen Vermögens. Abhängig vom spezifischen Agententyp im Modell kann ein Agent auch auf individuelle Informationen anderer Agenten zugreifen.[^1]

2. **Öffentliche Informationen:** Diese Informationen sind für alle Agenten zugänglich und werden ebenfalls im Investitionsentscheidungsprozess genutzt. Beispiele sind Nachrichten, die den Markt beeinflussen, oder der aktuelle Aktienkurs. Das Konzept der öffentlichen Informationen ermöglicht es, dass verschiedene Agententypen auf demselben Markt handeln, aber unterschiedliche öffentliche Informationen für ihre Entscheidungen heranziehen können. So könnte ein Agententyp Nachrichten von außerhalb des Marktes nutzen, während ein anderer die Kursentwicklung über die letzten $n$ Zeitschritte betrachtet.[^1]

3. **Investitionsentscheidungsprozess:** Dies ist eine mathematische Abbildung, die alle verfügbaren Informationen des Agenten – sowohl individuelle als auch öffentliche – verarbeitet, um neue individuelle Informationen für den nächsten Zeitschritt zu generieren und eine Preisentscheidung zu treffen. Formal wird dies als 
   $$
   A_i: \Omega \rightarrow \mathbb{R}^{J_i} \times \mathbb{R}
   $$
   beschrieben, wobei $\Omega$ die Menge aller relevanten Informationen darstellt und $J_i$ die Anzahl der individuellen Informationsstücke des Agenten $i$.[^1] Der von der Abbildung $A_i$ generierte Preis muss für alle Agenten übereinstimmen.

Das Design der Agenten in ABCEM-Modellen weicht bewusst vom idealisierten "homo oeconomicus"-Paradigma ab. Stattdessen werden Agenten oft als "bounded rational agents" im Sinne von Herbert Simon modelliert.[^1] Dies bedeutet, dass Investoren ihre Entscheidungen eher auf Heuristiken oder Verhaltensregeln basieren, anstatt komplexe Optimierungsprobleme zu lösen. Solche suboptimalen Handelsstrategien erweisen sich oft als erstaunlich gute Annäherungen an reale Investitionsprozesse und können psychologische Aspekte in die Entscheidungsfindung integrieren.[^1] Der SABCEMM-Simulator ist flexibel genug, um auch andere Konzepte wie den "Zero-Intelligence-Trader" zu unterstützen, der keine spezifische Strategie verfolgt.[^1]

**Beispielhafte Investorentypen und Formeln:**
- **Fundamentalisten:** Diese Investoren glauben an die Existenz eines "fairen Preises" ($S_f$) für einen Vermögenswert und erwarten, dass der Marktpreis zu diesem Wert konvergieren wird. Ihre Überschussnachfrage ($ed_{F}^i(S)$) ist eine monoton steigende Funktion der Differenz zwischen dem fairen und dem aktuellen Preis:
  $$
  ed_{F}^i(S) := D_i (S_f - S)
  $$
- **Chartisten (Technische Händler):** Im einfachsten Fall hängt ihre Überschussnachfrage ($ed_{C}^i(S)$) von der Differenz zwischen dem aktuellen Kurs ($S_k$) und dem Kurs des vorherigen Zeitschritts ($S_{k-1}$) ab:
  $$
  ed_{C}^i(S) := D_i (S_k - S_{k-1})
  $$

Zwei Agenten $A_i$ und $A_j$ ($i \neq j$) werden als vom selben Agententyp definiert, wenn ihre Investitionsentscheidungsabbildungen $A_i$ und $A_j$ identisch sind. Dies ist der Fall, wenn eine Abbildung durch eine einfache Permutation des Eingangsvektors der anderen erhalten werden kann.[^1]

### 3.2 Marktmechanismen

Der Marktmechanismus ist der zweite grundlegende Baustein und beschreibt, wie die individuellen Entscheidungen der Agenten aggregiert und in Preisbewegungen umgesetzt werden. Er besteht aus der Berechnung der Überschussnachfrage und dem Clearing-Mechanismus.

#### **Aggregierte Überschussnachfrage (ED):**
Die aggregierte Überschussnachfrage $ED$ von $N$ Agenten ist definiert als der Durchschnitt der mikroskopischen Überschussnachfragen $ed^i$ jedes einzelnen Agenten:
$$
ED(S) := \frac{1}{N} \sum_{i=1}^{N} ed^i(S)
$$
Hierbei ist $S$ der Aktienkurs, von dem die individuelle Überschussnachfrage $ed^i$ abhängt. Ein Wert von $ed^i = 0$ bedeutet, dass der Agent keine Aufträge erteilt. Ein positiver Wert ($ed^i > 0$) repräsentiert einen Kaufauftrag, während ein negativer Wert ($ed^i < 0$) einen Verkaufsauftrag widerspiegelt.[^1] Die genaue Form von $ed^i$ ist modellspezifisch.

**Beispiel aus dem Harras-Modell:**
$$
ed^i(S) = \frac{\sigma^i(S) S^{\gamma^i(S)} w^i(S)}{}
$$
wobei $\sigma^i$ die Investitionsposition (kaufen, halten, verkaufen), $\gamma^i$ den Investitionsanteil und $w^i$ das Vermögen des Agenten darstellt.[^1]

#### **Clearing-Mechanismen:**

SABCEMM bietet zwei Haupttypen von Clearing-Mechanismen zur Preisanpassung[^1]:

- **Rationaler Markt:** Der Preis ($S$) wird so bestimmt, dass die aggregierte Überschussnachfrage genau Null ist ($ED(S) = 0$). Aus mathematischer Sicht ist dies ein Problem der Nullstellensuche:
  $$
  0 \equiv \frac{1}{N} \sum_{i=1}^{N} \sigma^i(S) S^{\gamma^i(S)} w^i(S)
  $$
- **Irrationaler Markt:** Der Preis im nächsten Zeitschritt ($S_{k+1}$) wird basierend auf dem aktuellen Preis ($S_k$), der aggregierten Überschussnachfrage ($ED$) und einem Rauschterm ($\eta$) berechnet:
  $$
  S_{k+1} = M(S_k, ED, \eta)
  $$
  Ein Beispiel für einen irrationalen Markt (z.B. im Harras-Modell):
  $$
  S_{k+1} = S_k + \frac{\lambda}{N}\sum_{i=1}^{N} \sigma^i(S) S^{\gamma^i(S)} w^i(S)
  $$
  wobei $\lambda > 0$ die Markttiefe darstellt.

#### Das Disequilibrium-Modell von Beja und Goldman

Hier wird die Preisänderungsrate proportional zur aggregierten Überschussnachfrage modelliert:
$$
\frac{d}{dt}P = H(ED(P)), \quad P := \log(S)
$$
$H$ ist eine monoton steigende Funktion der Überschussnachfrage $ED$, die bei Null verschwindet.

Eine Linearisierung erster Ordnung von $H$ um $H(0) = \lambda$ führt zu:
$$
\frac{d}{dt}P = \lambda ED(P)
$$
Um zufällige Fehler oder externe Nachrichten zu berücksichtigen:
$$
\frac{d}{dt}P = \lambda ED(P) + \eta, \quad \eta \sim N(0,1)
$$

Die allgemeinste Form einer stochastischen Differentialgleichung, die viele Marktmechanismen in ABCEM-Modellen abdeckt:
$$
dS = F(S, ED)dt + G(S, ED)dW
$$
wobei $dW$ ein Wiener-Prozess ist.

Diskretisierte Version (Euler-Verfahren):
$$
S_{k+1} = S_k + F(S_k, ED_k) + G(S_k, ED_k)\eta
$$

**Technische Begriffe:**
- _Numerische Diskretisierung:_ Um kontinuierliche Modelle auf dem Computer zu simulieren, werden sie in diskrete Zeitschritte zerlegt (z.B. Euler-Verfahren).
- _Wiener-Prozess:_ Modelliert zufällige Preisbewegungen (Brownsche Bewegung).
- _Itô/Stratonovich SDE:_ Verschiedene Interpretationen stochastischer Differentialgleichungen, wichtig für die Modellierung des Rauschens.

### 3.3 Umgebung und Kopplung

Der dritte Aspekt des abstrakten Meta-Modells ist die "Umgebung" oder "Kopplung". Dies ist ein neuartiges Konzept, das zusätzliche Interaktionsmechanismen zwischen den Agenten einführt, die über den globalen Marktpreis hinausgehen.[^1]

Ein häufig verwendeter Umgebungsmechanismus ist der Herding-Mechanismus. Kirman war wohl der erste, der dieses Konzept in ökonomischen Modellen anwandte.[^1] Herding führt dazu, dass Investoren dazu neigen, den Entscheidungen anderer zu folgen, was hohe Korrelationen zwischen Finanzagenten erzeugt.

**Beispiel (Cross-Modell) für den Herding-Mechanismus:**
$$
c_i(t+\Delta t) =
\begin{cases}
c_i(t) + \Delta t |ED(t)|, & \text{wenn } \sigma_i(t)ED(t) < 0 \\
c_i(t), & \text{sonst}
\end{cases}
$$
Erreicht der Herding-Druck $c_i$ einen individuellen Schwellenwert $\alpha_i > 0$, wechselt der Agent seine Position und $c_i$ wird auf Null zurückgesetzt.[^1]

Ein weiterer wichtiger Kopplungsmechanismus ist der Switching-Mechanismus zwischen verschiedenen Agentengruppen, häufig ausgelöst durch ein "Fitnessmaß", das z.B. vergangene Gewinne verschiedener Strategien vergleicht.

Die Modellierung der "bounded rationality" dient als Brücke zwischen Psychologie und Ökonomie. Sie ermöglicht es, menschliche Heuristiken, Herdenverhalten, Blasenbildung etc. realitätsnäher zu modellieren.

Das Konzept der "Umgebung" abstrahiert komplexe, nicht-preisliche Interaktionen und ist entscheidend für die Emergenz stilisierter Fakten. Beispiele wie Herding- und Switching-Mechanismen erzeugen zusätzliche Korrelationen und ermöglichen die Bildung stilisierter Fakten, die in klassischen Modellen nicht erklärbar sind.

---

## 4. Die SABCEMM-Software: Architektur und Funktionalität

Der SABCEMM-Simulator ist ein robustes Softwarewerkzeug, das auf einem durchdachten objektorientierten Design basiert. Diese Architektur ermöglicht es, die Komplexität von ABCEM-Modellen effizient zu verwalten, neue Modelle einfach zu erstellen und Simulationen mit hoher Leistung durchzuführen.

### 4.1 Objektorientiertes Design und seine Vorteile

Die Software basiert auf dem Prinzip der Trennung der Belange (Edsger W. Dijkstra) und folgt einem klassenbasierten objektorientierten Programmieransatz in C++.[^1] Vorteile:

- **Isolierte Implementierung:** Komponenten können unabhängig entwickelt und getestet werden.
- **Reduzierung des Programmieraufwands:** Wiederverwendbarkeit bestehender Bausteine reduziert den Aufwand für neue Modelle.[^1]
- **Flexibilität und Erweiterbarkeit:** Neue Modelle können mit minimalem Aufwand durch Rekombination vorhandener Bausteine erstellt und getestet werden.[^1]

Die Software ist umfassend dokumentiert und unter einer Open-Source-Lizenz auf GitHub verfügbar.[^1]

### 4.2 Der Numerische Kern

Der Kern von SABCEMM ist um drei abstrakte Klassen herum aufgebaut:

- **Agent (Abstrakte Klasse):** Definiert die Schnittstelle und Eigenschaften, die jeder Agententyp benötigt. Wichtige Variablen: Stock, Cash, Decision ($\in \{-1,0,1\}$), Trading Volume.[^1] Wichtige Methoden: `updateAgent()`, `updateBisection()` (nur für rationale Märkte). Modelle, die eine Umgebung benötigen, müssen diese in der Agent-Klasse integrieren.

- **PriceCalculator (Abstrakte Klasse):** Schnittstelle für die Berechnung des neuen Aktienkurses. Die Methode `calculatePrice` bestimmt den neuen Kurs pro Zeitschritt.[^1]

- **ExcessDemandCalculator (Abstrakte Klasse):** Schnittstelle für die Berechnung der aggregierten Überschussnachfrage. Methode `calculateExcessDemand` sammelt die Überschussnachfrage aller Agenten.[^1]

Die **StockExchange-Klasse** orchestriert das Zusammenspiel aller Komponenten: Sie verwaltet die Agentenliste, ruft vor und nach jedem Zeitschritt `preStep()` und `postStep()` auf, und in jedem Zeitschritt (`step()`) wird zuerst die Nachfrage berechnet, dann der Preis angepasst und die Agenten aktualisiert.[^1]

### 4.3 Erstellung neuer Modelle

Ziel ist es, die Implementierung verschiedener ABCEM-Modelle zu vereinfachen und schnelle Simulationen mit großen Agentenzahlen zu ermöglichen.[^1]

- **Rekombination bestehender Bausteine:** Implementierungen der abstrakten Klassen dienen als modulare Bausteine. Für bekannte Modelle wie Harras, LLS und Cross sind alle notwendigen Blöcke bereits implementiert. Neue Modelle können durch Rekombination dieser Blöcke erstellt werden.[^1]

- **Konfiguration über XML-Eingabedateien:** Die Kombination von Bausteinen und deren Parameter werden in XML-Dateien festgelegt. Diese sind gut strukturiert, eignen sich für Versionskontrolle und ermöglichen einen reproduzierbaren Workflow. Parameterstudien können durch Skripte automatisiert werden.[^1]

### 4.4 Datenverwaltung und Ausgabeformate

SABCEMM bietet zwei Formate für Simulationsausgaben[^1]:

- **CSV-Dateien:** Einfache Speicherung aller Daten in CSV-Dateien.
- **HDF5-Dateien:** Speicherung aller Ergebnisse in einer HDF5-Datei, inkl. der verwendeten XML-Eingabedatei. HDF5 ist ein selbstbeschreibendes, hierarchisches Datenformat und kann z.B. mit Python (h5py), MATLAB oder Excel (PyHexad-Add-in) ausgelesen werden.

Die Nachbearbeitung und Visualisierung der Ergebnisse erfolgt durch den Nutzer, nicht durch SABCEMM selbst.

---

## 5. Rechentechnische Aspekte und Effizienz des SABCEMM-Simulators

### 5.1 Softwaretests und Zuverlässigkeit

SABCEMM implementiert Tests mithilfe der GoogleTest-Bibliothek.[^1] Es werden drei Ansätze genutzt:

- **Unit Tests:** Testen einzelne Funktionen auf Korrektheit.
- **Integration und Acceptance Tests:** Prüfen komplette Simulationsschritte gegen manuell berechnete Werte, oft mit deterministischen Zufallszahlen.[^1]
- **Qualitative Vergleiche:** Ergebnisse werden mit Diagrammen aus Publikationen verglichen.

Kombiniert führen diese Methoden zu hoher Zuverlässigkeit der Software.[^1]

### 5.2 Skalierbarkeit und Recheneffizienz

Die Laufzeit von SABCEMM-Simulationen skaliert linear mit der Anzahl der Agenten und Zeitschritte – bestätigt durch Experimente mit Cross-, Harras- und LLS-Modellen.[^1] Der C++-Code ist hoch effizient, sodass auch Simulationen mit mehreren Millionen Agenten auf Laptops möglich sind. Die hohe Allgemeinheit des Meta-Modells erschwert jedoch die Ausnutzung von Parallelität und Vektorisierung, was aber durch die Flexibilität und gute Performance für realistische Modelle aufgewogen wird.[^1]

### 5.3 Pseudozufallszahlen (PZNs): Bedeutung und Effizienz der Generierung

Pseudozufallszahlen sind essenziell für ABCEM-Modelle. Ihr Bedarf wächst schnell mit der Anzahl der Agenten und Zeitschritte:

| Agentenanzahl | Zufallszahlen pro Agent/Schritt | Gesamtbedarf (ca.)    |
|---------------|-------------------------------|-----------------------|
| 100           | 1                             | 1.010.000             |
| 1.000         | 1                             | 10.010.000            |
| 10.000        | 1                             | 100.010.000           |

SABCEMM unterstützt folgende Zufallszahlengeneratoren[^1]:

- NAG (Numerical Algorithms Group): g05dyc, g05dac, g05ddc
- Intel MKL: VSL BRNG MT2203
- C++-Standardbibliothek: mt19937_64

Alle sind Varianten des Mersenne Twister, der für große Simulationen empfohlen wird. Ältere C++-Standards sollten vermieden werden, da deren Zufallszahlengeneratoren nicht ausreichend sind.[^1]

Effizienzsteigerung durch Vorab-Generierung eines Zufallszahlenpools ("Batch Generation"). Dies reduziert die Laufzeit erheblich:

| Agentenanzahl | Laufzeit C++ sequenziell | Laufzeit MKL Batch | Generierungszeit C++ | Generierungszeit MKL |
|---------------|------------------------|-------------------|---------------------|----------------------|
| 2.500         | 8,65s                  | 5,61s             | 4,46s               | 0,346s               |
| 10.000        | 39,52s                 | 30,63s            | 17,84s              | 1,383s               |

Die Beschleunigung durch MKL-Batch beträgt bis zu 35% für die gesamte Simulation und 92% für die Zufallszahlengenerierung.

---

## 6. Fazit und Ausblick

Der SABCEMM-Simulator stellt ein leistungsstarkes, vielseitiges Open-Source-Werkzeug speziell für die Simulation heterogener Multi-Agenten-ABCEM-Modelle dar. Im Vergleich zu allgemeinen Agenten-basierten Simulatoren liegt der Fokus explizit auf den Anforderungen von Wirtschaftsmarktmodellen.[^1]

Die fünf Hauptmerkmale von SABCEMM:[^1]

- **Allgemeinheit:** Basierend auf einem sehr allgemeinen Meta-Modell, das vielfältige Wirtschaftsmarktmodelle ermöglicht.
- **Rekombination:** Objektorientiertes Design erlaubt flexible Rekombination von Modellbausteinen.
- **Vergleichbarkeit:** Gemeinsame Plattform und Auswahl an Zufallszahlengeneratoren ermöglichen objektive Modellvergleiche.
- **Erweiterbarkeit:** Neue Modelle können einfach durch modulare Erweiterung implementiert werden.
- **Effizienz:** Optimiert für sehr große Agentenzahlen ($>10^6$), was die Untersuchung und Vermeidung von Finite-Size-Effekten ermöglicht.

Zukünftige Arbeiten umfassen die Demonstration der Flexibilität des Simulators, den Vergleich von Modellen hinsichtlich stilisierter Fakten, die Implementierung weiterer ABCEM-Modelle und die Nutzung für Sensitivitätsanalysen und Parameteranpassung.[^1] SABCEMM wird somit als unverzichtbares Werkzeug für die ökonophysikalische Forschung etabliert und trägt entscheidend zum Verständnis der Dynamik von Finanzmärkten bei.

---

## Referenzen

[^1]: 1801.01811v2.pdf
