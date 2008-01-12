//
// File: ProteicAlphabet.h
// Created by: Guillaume Deuchst
//             Julien Dutheil
// Created on: Tue Jul 22 2003
//

/*
Copyright or � or Copr. CNRS, (November 17, 2004)

This software is a computer program whose purpose is to provide classes
for sequences analysis.

This software is governed by the CeCILL  license under French law and
abiding by the rules of distribution of free software.  You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/


#ifndef _PROTEICALPHABET_H_
#define _PROTEICALPHABET_H_

#include "AbstractAlphabet.h"

namespace bpp
{

/**
 * @brief This alphabet is used to deal with proteins.
 *
 * It supports all 20 amino-acids with their standard denomination.
 * Gaps are coded by '-', unresolved characters are coded by 'X'.
 */

class ProteicAlphabet:
  public AbstractAlphabet
{
	public:
		ProteicAlphabet();
		virtual ~ProteicAlphabet() {}
	
	public:
		unsigned int getSize() const { return 20; }
		unsigned int getNumberOfTypes() const { return 23; }
    int getUnknownCharacterCode() const { return 22; }
 		vector<int   > getAlias(      int      state) const throw (BadIntException);
		vector<string> getAlias(const string & state) const throw (BadCharException);
    bool isUnresolved(int state) const { return state > 19; }
    bool isUnresolved(const string & state) const { return charToInt(state) > 19; }
	  string getAlphabetType() const { return "Proteic alphabet"; }
	
	public:

		/**
		 * @name Specific methods
		 *
		 * @{
		 */
    
		/**
		 * @brief Get the abbreviation (3 letter code) for a state coded as char.
		 *
		 * @param aa Char description of the amino-acid to analyse.
		 */
		string getAbbr(const string & aa) const throw (AlphabetException);
	
		/**
		 * @brief Get the abbreviation (3 letter code) for a state coded as int.
		 *
		 * @param aa Int description of the amino-acid to analyse.
		 */
		string getAbbr(int aa) const throw (AlphabetException);
		/** @} */
		
};

} //end of namespace bpp.

#endif // _PROTEICALPHABET_H_

