/*
 * Copyright 2014-2016 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.kaaproject.kaa.server.admin.client.mvp.place;

import com.google.gwt.place.shared.PlaceTokenizer;
import com.google.gwt.place.shared.Prefix;

import org.kaaproject.kaa.server.admin.client.util.Utils;

public class UserProfilePlace extends TreePlace {

  public UserProfilePlace() {
  }

  @Override
  public boolean equals(Object obj) {
    return obj != null && (obj instanceof UserProfilePlace);
  }

  @Override
  public String getName() {
    return Utils.constants.accountProfile();
  }

  @Override
  public boolean isLeaf() {
    return true;
  }

  @Override
  public TreePlace createDefaultPreviousPlace() {
    return null;
  }

  @Prefix(value = "usrProf")
  public static class Tokenizer implements PlaceTokenizer<UserProfilePlace>, PlaceConstants {

    @Override
    public UserProfilePlace getPlace(String token) {
      return new UserProfilePlace();
    }

    @Override
    public String getToken(UserProfilePlace place) {
      PlaceParams.clear();
      return PlaceParams.generateToken();
    }
  }

}
