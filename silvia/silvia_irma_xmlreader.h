/* $Id$ */

/*
 * Copyright (c) 2013 Roland van Rijswijk-Deij
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 silvia_irma_xmlreader.h

 XML reader that will read and parse the XML file types that are relevant for
 Silvia and the IRMA project
 *****************************************************************************/

#ifndef _SILVIA_IRMA_XMLREADER_H
#define _SILVIA_IRMA_XMLREADER_H

#include <gmpxx.h>
#include "silvia_types.h"
#include "silvia_verifier_spec.h"
#include "silvia_issue_spec.h"
#include <vector>
#include <memory>

/**
 * IRMA XML reader class
 */
class silvia_irma_xmlreader
{
public:
	/**
	 * Get the one-and-only instance of the IRMA XML reader object
	 * @return the one-and-only instance of the IRMA XML reader object
	 */
	static silvia_irma_xmlreader* i();
	
	/**
	 * Reads issuer and verifier descriptions to create a verifier
	 * specification that can be used by Silvia
	 * @param id_file_name File name of the issuer description file
	 * @param vd_file_name File name of the verifier description file
	 * @return A new verifier specification object or NULL if reading/parsing of one of the files failed
	 */
	silvia_verifier_specification* read_verifier_spec(const std::string id_file_name, const std::string vd_file_name);

	/**
	 * Reads a credential issue specification from file
	 * @param issue_spec_file_name File name of the credential issue specification
	 * @return A new issue specification object or NULL if reading/parsing on the file failed
	 */
	silvia_issue_specification* read_issue_spec(const std::string issue_spec_file_name);
	
private:
	// The one-and-only instance
	static std::auto_ptr<silvia_irma_xmlreader> _i;
};

#endif // !_SILVIA_IRMA_XMLREADER_H

