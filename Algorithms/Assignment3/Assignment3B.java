// Name: Emmett Casey

import java.util.*;
import java.math.*;
import static java.lang.Math.*;

public class Assignment3B
{
	
	public int numStep(int[] sequence)
	{
		int addPerfomed = 0;
		int i = 0;
		int j = sequence.length - 1;
		while (i < j)
		{
			if (sequence[i] < sequence[j])
			{
				sequence[i + 1] += sequence[i];
				addPerfomed++;
				i++;
			}
			else if (sequence[i] > sequence[j])
			{
				sequence[j - 1] += sequence[j];
				addPerfomed++;
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
		return addPerfomed;
	}
}