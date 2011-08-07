/**
 * @addtogroup OVAL
 * @{
 * @addtogroup OVALDIR
 * Interface for Directives model
 * @{
 *
 * @file
 *
 * @author "Peter Vrabec" <pvrabec@redhat.com>
 *
 *
 */

/*
 * Copyright 2011 Red Hat Inc., Durham, North Carolina.
 * All Rights Reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors:
 *      "David Niemoller" <David.Niemoller@g2-inc.com>
 */

#ifndef OVAL_DIRECTIVES_H_
#define OVAL_DIRECTIVES_H_

#include "oval_types.h"

/**
 * @typedef oval_result_directive_content_t
 * Values for the directives controlling the expected content of the results file
 */
typedef enum {
	OVAL_DIRECTIVE_CONTENT_UNKNOWN = 0, /**< Undefined value */
	OVAL_DIRECTIVE_CONTENT_THIN = 1,    /**< Only the minimal amount of information will be provided. */
	OVAL_DIRECTIVE_CONTENT_FULL = 2     /**< Very detailed information will be provided allowing in-depth reports to be generated from the results. */
} oval_result_directive_content_t;


/**
 * @struct oval_result_directives
 * This structure holds instance of OVAL Result Directives for particular oval_results_model.
 * OVAL Result Directives describes what information has been included in the results file, therefore  
 * it's necessarry to setup this structure before exporting oval_results_model. Usage example:
 *
 * @code
 * struct oval_result_directives * res_direct = oval_result_directives_new();
 * oval_result_directives_set_reported(res_direct, OVAL_RESULT_TRUE | OVAL_RESULT_FALSE , true);
 * oval_result_directives_set_content(res_direct,OVAL_RESULT_FALSE | OVAL_RESULT_TRUE | OVAL_RESULT_ERROR , OVAL_DIRECTIVE_CONTENT_FULL);
 * .....
 * oval_result_directives_free(res_direct);
 * @endcode
 *
 * 
 */
struct oval_result_directives;

/**
 * Create new OVAL Results Directives instance. Directives are setup NOT to report any type of result by default.
 * @memberof oval_result_directives
 */
struct oval_result_directives *oval_result_directives_new(void);

/**
 * @memberof oval_result_directives
 */
void oval_result_directives_free(struct oval_result_directives *);


/**
 * @name Setters
 * @{
 */
/**
 * Set (or unset) result types that are intended to be reported. Functions does not override previous settings.
 * @memberof oval_result_directives
 */
void oval_result_directives_set_reported(struct oval_result_directives *, int flag, bool val);
/**
 * Configure the depth of infomation.
 * @memberof oval_result_directives
 */
void oval_result_directives_set_content(struct oval_result_directives *, int flag, oval_result_directive_content_t);
/** @} */

/**
 * @name Getters
 * @{
 */
/**
 * @memberof oval_result_directives
 */
bool oval_result_directives_get_reported(struct oval_result_directives *, oval_result_t);
/**
 * @memberof oval_result_directives
 */
oval_result_directive_content_t oval_result_directives_get_content(struct oval_result_directives *, oval_result_t);
/** @} */

/**
 * @name Evaluators
 * @{
 */
/** @} */


#endif				/* OVAL_DIRECTIVES_H_ */
