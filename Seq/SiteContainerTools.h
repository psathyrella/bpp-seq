//
// File: SiteContainerTools.h
// Created by: Julien Dutheil
// Created on: Fri Dec 12 18:55:06 2003
//

#ifndef _SITECONTAINERTOOLS_H_
#define _SITECONTAINERTOOLS_H_

#include "SiteContainer.h"

typedef vector<unsigned int> SiteSelection;

/**
 * @brief Some utililitary methods to deal with site containers.
 */
class SiteContainerTools
{
	public:
		SiteContainerTools() {}
		virtual ~SiteContainerTools() {}

	public:

		/**
		 * @brief Retrieves sites without gaps from SiteContainer.
		 *
		 * This function build a new SiteContainer instance with only sites without gaps.
		 * The container passed as input is not modified, all sites are copied.
		 *
		 * @param sites The container to analyse.
		 * @return A pointer toward a new SiteContainer with only sites with no gaps.
		 */
		static SiteContainer * getSitesWithoutGaps(const SiteContainer & sites);

		/**
		 * @brief Retrieves complete sites from SiteContainer.
		 *
		 * This function build a new SiteContainer instance with only complete sites,
		 * i.e. site with fully resolved states (no gap, no unknown caracters).
		 * The container passed as input is not modified, all sites are copied.
		 *
		 * @param sites The container to analyse.
		 * @return A pointer toward a new SiteContainer with only complete sites.
		 */
		static SiteContainer * getCompleteSites(const SiteContainer & sites);

		/**
		 * @brief Get a site set without gap-only sites.
		 *
		 * This function build a new SiteContainer instance without gap only sites.
		 * The container passed as input is not modified, all sites are copied.
		 *
		 * @param sites The container to analyse.
		 * @return A pointer toward a new SiteContainer.
		 */
		static SiteContainer * removeGapOnlySites(const SiteContainer & sites);

		/**
		 * @brief Create a new container with a specified set of sites.
		 *
		 * A new VectorSiteContainer is created with specified sites.
		 * The destruction of the container is up to the user.
		 * Sequences are specified by their indice, beginning at 0.
		 * No position verification is performed, based on the assumption that
		 * the container passed as an argument is a correct one.
		 * Redundant selection is not checked, so be careful with what you're doing!
		 *
		 * @param sequences The container from wich sequences are to be taken.
		 * @param selection The positions of all sites to retrieve.
		 * @return A new container with all selected sites.
		 */
		static SiteContainer * getSelectedSites(const SiteContainer & sequences, const SiteSelection & selection);


		/**
     * @brief create the consensus sequence of the alignment.
     *
     * In case of ambiguity (for instance a AATT site), one state will be chosen arbitrarily.
     *
     * @param sc a site container
     * @param name the name of the sequence object that will be created. 
     * @param ignoreGap Tell if gap must be counted or not. If not (true option), only fully gapped sites will result in a gap in the consensus sequence. 
     * @param resolveUnknown Tell is unknnown characters must resolved. In a DNA sequence for instance, N will be counted as A=1/4, T=1/4, G=1/4 and C=1/4. Otherwise it will be counted as N=1.
     * If this option is set to true, a consensus sequence will never contain an unknown character.
     * @return A new Sequence object with the consensus sequence.
     */

		static const Sequence * getConsensus(const SiteContainer & sc,string name="consensus", bool ignoreGap = true, bool resolveUnknown = false);
    
    /**
     * @brief Change all gaps to unknown state in a container, according to its alphabet.
     *
     * @param sites The container to be modified.
     */
    static void changeGapsToUnknownCharacters(SiteContainer & sites);

    /**
     * @brief Resolve a container with "." notations.
     *
     * @code
     * ATGCCGTTGG
     * .C...A..C.
     * ..A....C..
     * @endcode
     * will results in
     * @code
     * ATGCCGTTGG
     * ACCCCATTCG
     * ATACCGTCGG
     * @endcode
     * for instance.
     * The first sequence is here called the "reference" sequence.
     * It need not be the first in the container.
     * The alphabet of the input alignment must be an instance of the DefaultAlphabet class, the only one which support dot characters.
     * A new alignment is created and returned, with the specified alphabet.
     *
     * If several sequences that may be considered as reference are found, the first one is used.
     * 
     * @param dottedAln The input alignment.
     * @param resolvedAlphabet The alphabet of the output alignment.
     * @return A pointer toward a dynamically created SiteContainer with the specified alphabet (can be a DefaultAlphabet).
     * @throw AlphabetException If the alphabet of the input alignment is not of class DefaultAlphabet, or if one character does not match with the output alphabet.
     * @throw Exception If no reference sequence was found, or if the input alignment contains no sequence.
     */
    static SiteContainer * resolveDottedAlignment(const SiteContainer & dottedAln, const Alphabet * resolvedAlphabet) throw (AlphabetException, Exception);

};

#endif	//_SITECONTAINERTOOLS_H_

