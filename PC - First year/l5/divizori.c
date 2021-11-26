int suma_divizori(int n)
{
	/*
	 * Explicatie algoritm:
	 *
	 * Fiecare divizor al unui numar are o pereche divizor.
	 * De exemplu, 10 se imparte la 2, dar se imparte si la
	 * 10 / 2, adica 5. In general, daca n se imparte la d
	 * atunci se va imparti si la n / d. Divizorii se pot
	 * imparti in doua categorii: inainte de radical si dupa
	 * radical. Ceea ce gasim dupa radical sunt, de fapt, 
	 * perechile divizorilor inainte de radical. De exemplu,
	 * radical din 16 este 4. Inainte de 4 gasim divizorul 2,
	 * iar dupa 4 il gasim pe 8. 2 este in pereche cu 8, iar 4
	 * e propria sa pereche. De aceea, nu va fi nevoie sa iteram
	 * dupa radical din n.
	 */ 

	int suma = 1; // 1 e primul divizor

	for(int d = 2; d * d <= n; ++d)
	{
		if(n % d == 0) {
			suma += d;
			
			// Doar cand nu e radacina adunam si perechea.
			if (d * d != n) {
				suma += n / d;  
			}
		}
	}	

	return suma;
}
