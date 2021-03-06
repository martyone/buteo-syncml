/*
* This file is part of buteo-syncml package
*
* Copyright (C) 2010 Nokia Corporation. All rights reserved.
*
* Contact: Sateesh Kavuri <sateesh.kavuri@nokia.com>
*
* Redistribution and use in source and binary forms, with or without 
* modification, are permitted provided that the following conditions are met:
*
* Redistributions of source code must retain the above copyright notice, 
* this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, 
* this list of conditions and the following disclaimer in the documentation 
* and/or other materials provided with the distribution.
* Neither the name of Nokia Corporation nor the names of its contributors may 
* be used to endorse or promote products derived from this software without 
* specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
* THE POSSIBILITY OF SUCH DAMAGE.
* 
*/

#include "SyncMLHdrTest.h"

#include "SyncMLHdr.h"
#include "QtEncoder.h"
#include "Fragments.h"
#include "TestUtils.h"

#include "TestLoader.h"

using namespace DataSync;

void SyncMLHdrTest::testSyncMLHdr_11()
{
    HeaderParams headerParams;
    headerParams.verDTD = SYNCML_DTD_VERSION_1_1;
    headerParams.verProto = DS_VERPROTO_1_1;
    headerParams.msgID = 100;
    headerParams.sessionID = "12345";
    headerParams.sourceDevice = "addressbook";
    headerParams.targetDevice = "card";
    headerParams.meta.maxMsgSize = 20;
    headerParams.meta.maxObjSize = 40;

    SyncMLHdr hdr(headerParams);

    QByteArray expected;
    QVERIFY( readFile( "data/SyncMLHdrTest_11.txt", expected ) );
    QtEncoder encoder;
    QByteArray output;
    QVERIFY( encoder.encodeToXML( hdr, output, true ) );
    QCOMPARE( output, expected );
}

void SyncMLHdrTest::testSyncMLHdr_12()
{
    HeaderParams headerParams;
    headerParams.verDTD = SYNCML_DTD_VERSION_1_2;
    headerParams.verProto = DS_VERPROTO_1_2;
    headerParams.msgID = 100;
    headerParams.sessionID = "12345";
    headerParams.sourceDevice = "addressbook";
    headerParams.targetDevice = "card";
    headerParams.meta.maxMsgSize = 20;
    headerParams.meta.maxObjSize = 40;

    SyncMLHdr hdr(headerParams);

    QByteArray expected;
    QVERIFY( readFile( "data/SyncMLHdrTest.txt", expected ) );
    QtEncoder encoder;
    QByteArray output;
    QVERIFY( encoder.encodeToXML( hdr, output, true ) );
    QCOMPARE( output, expected );
}


TESTLOADER_ADD_TEST(SyncMLHdrTest);
