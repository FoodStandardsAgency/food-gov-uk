<?php
/**
 * @file
 * section_landing_pages_features.features.node_export_features.inc
 */

/**
 * Implements hook_node_export_features_default().
 */
function section_landing_pages_features_node_export_features_default() {
  $node_export = array(
  'code_string' => 'array(
  (object) array(
      \'vid\' => \'198\',
      \'uid\' => \'1\',
      \'title\' => \'Policy and advice\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'cd3e56b2-551b-49f3-b74e-8924fc448a51\',
      \'nid\' => \'3\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442141\',
      \'changed\' => \'1395490256\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'347a84d6-9e63-48bc-a5ef-3e7861750fe4\',
      \'revision_timestamp\' => \'1395490256\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>In this section you&#39;ll find background information on a range of topics as well as our ongoing work in these areas, including GM foods, additives, allergy and campylobacter.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>In this section you\'ll find background information on a range of topics as well as our ongoing work in these areas, including GM foods, additives, allergy and campylobacter.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency carries out a range of work to make sure food is safe to eat, including funding research on chemical, microbiological and radiological safety, as well as food hygiene, GM and allergy.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency carries out a range of work to make sure food is safe to eat, including funding research on chemical, microbiological and radiological safety, as well as food hygiene, GM and allergy.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'policy.jpg\',
            \'uri\' => \'public://banner-image/policy.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'22716\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'0bd8a845-c201-4e9f-94de-59b6ee70fa9e\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'/9j/4AAQSkZJRgABAgAAZABkAAD/7AARRHVja3kAAQAEAAAAPAAA/+4ADkFkb2JlAGTAAAAAAf/bAIQABgQEBAUEBgUFBgkGBQYJCwgGBggLDAoKCwoKDBAMDAwMDAwQDA4PEA8ODBMTFBQTExwbGxscHx8fHx8fHx8fHwEHBwcNDA0YEBAYGhURFRofHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8f/8AAEQgApAHOAwERAAIRAQMRAf/EAKwAAAEFAQEBAAAAAAAAAAAAAAUCAwQGBwEACAEAAwEBAQEAAAAAAAAAAAAAAQIDAAQFBhAAAgECBAQDBAcGAwYFAgcAAQIDEQQAIRIFMUETBlFhInGBMhSRocFCUiMHsdFicjMV8YJD4ZKiUyQW8LLCNAjSY+Lyk6NUJRcRAAICAgICAQQBAgUEAwAAAAABEQIhAzESQQRRYXEiEzKBBfCRobEUwdFCYlIjM//aAAwDAQACEQMRAD8A+grieSw2R5ZT07m7q8jk10NICSfZGgLY5G4qUWWI2K2NvtUcujTPd0kVDxUMAsan+WPSPpxtahGbH7iJdQii+L0hT/GzUQ+71Ph0gCbmwtpZo7SNiiRgk04iNPiNfE1p78BqcAkqnc1nJv1wbVHrt9hIAbYfC0yAFQ3iI68PxezEbrt9jo1KMgVLHco7royJqB4Efb5Ymkzo7ITcRTyF44DpiT+rIOJ/hGMwoHxdJZdBQauCqaAmmeAmZ1GNx3qYOYrWP4ci/I0wLX+Bq6/kas+5tyVhEYxUCmdcL+xj/rQuWWZ5jM1KnOgxG2StWhyC9NSrZVzanE4NWM4HWkEwJHAc/H2YqmI0MOVYUrwwSbUEdpemQfoYcsaYN1k7aXstpG2ltSCQyxL+En4h7Dh+8r7HNs1QFrXe7Z5FfV+RcrpfyblXFFZT9GQaJ8V2j2ySKwMtm1G8Sn+GEeFPmv8AsaM/crncm2Rndri1rptO4IupAeSX1uKr/wDqJie6n5Y/8v8AcajwGu292bcNntLyY/8AUw/9HfDmHTIMfbkcVreUr/0YrUSgjcflzJKc1+CQfwnFL4ciI7C2jVC3+mcv5TwxqYwZgVI1jvLzbHyiu1M1ufBx8VPqOF14bqO85J1hdlxDNJxkrb3Q8JEyr78C2LT84AdcugeNf6ls2uPzXCxiPNRj06W8+uGUBrXcYyrKeFSKEe8YGO30sD/oZy1xdbNdw3b1a62KX5O+8ZLOT+k58fTliFX0t9sMd5RfbaaMSNEDqt516sPgUcZjHRXDdRH8gN4zaM8H3rFqp528mY/3eGEuoz8DJjciDqSQA/lzDqRHwbAjwER1SOldkZp+Xcezh+3C+Uwg3b7W2giuYUGkyXEky0yNGPLFapRAGPCEhtUgp4TLx/zDCNGI29XbmxmtRTWUNSOBFOOH8GgFWkbO0JGfUgGj2pnTDPgwYjiWopkk4qD4OMKYkgRFS0q6o5B0riOla1yGWMYuPZ/ZNn2pZvcNSTuK6jaN5qAGztWaogWn+owp1G/y8sdWrUqL6kNmxvHgcvbFXUA8eNPLjnixEqe57VHISdHA5E/QMsExXflRHMdHxA0FfoxgC977e2PuK3FtvFqsjqumG6T0TxHxSQZ6R+E5YV1GTKttv6M9u29xJd7puk95tsdHtrVFEDSrX78gJ9P8oFcRteCyUmm7JZRLaxKsCwWsACWNoookcQ+Gg/fjlveSqQeNi8kBkiWgHxZZGmJMIttxuLNLa3sYTcXNyw1qPiVBQivIaq0BxHZuaxXLLa9aeXwS7WG5gtRHuN/Ld2k6SO1mw9cdwX1Cj/FVSopjVbj8nIbROFA/21DtVnurX6zSGSQdNuo5KpGh1MzAk6mrkDjaoq5NebKC0L3Ds0wCxMSxGSM2mtOIGojHUttX5Od0aPNuN1cqqxxaIqVWpypiiYjQ18pNLKumpJOdMK5kKHrjYY5FYFFAPEFQ1fbXFoEKB3f2KIYZLzbgqOvqlhpRWA4lQOfliN6QWpfwyk216sCkRpqhY5xnKteJAxKS0A/e+2EmVrvaiATnJZnInmSn/wBOA18BTKuIgp9Vag0IPEH2YnJQUzqOHHGCJ1tX7MYB9Xb5FJum5wbbWkAYfMAcowBJKPeuiP3nHoXy4POWA7MCZagUKjSg8ydI+04oxRmFV6zTEZRKXH8zDQn0Itf82HAMXW62e1bRuW8XlBBZwu0jHmIgXcD2nLCOySbYUpcFG7DF9/2ta3V4D87fmW9nVuIa5kMlD7AwxDV/E7GlI3vW4XLyi2ss5VB6r1yHljWfwMkP7Jokt1gZa6qsw4k054NeAPkr3cMdxHIdK6VkyVqU9Nc6eWOXa2js1VTItrGqwhSBnwONRjXqLWOEMKgavLDEmhUsPoqv+3AaMgRcOI7ijejUAAx8uOJtj5FrPNoIjYGmCgOx0xTFAztnxK4oBOR1fhA4qeOCaBsRqr5H0HkcALIG52VzbxST2I109UltyPiyeDftwUQ2a/KIu0d72+tGl9BYdOYHnTgcUVzmdQ5uF6u67BNDBIP7htrrdWT1zLRnUv8AvLVcLE0jzXgHDE9vbjbx9waA2nbu44BNEnJblR6l9tajA1RLr4sa3E/Bc0YXFqY3/qJWOT2jnjor+VYfJJ4YyjECORviQ9Kb7DhU+H/QIP7hidY4r2EVmtG1jzXmPeMbYoasGvwMLMjXemNq2+4xiSE+EqCo+lf2Ya9eygCJhudSw3fNfy5x9R+vEu3Fv6MZfB5lJSW3U+tD1rc/XhbV5S+6DJWe7beAS2u9MP8ApbtPkN1HgkhpG5/kfCXhpW+QrGCP2rez/Iz7VOdW4bFJRTzeA8Ke7BTbrPmpms/cObuEpb7iucYHSuPOOTn/AJWxZ5UioGuriF0Gc1q1UPiv+GILj7DjTOmtwc4rpCR/MBg+fuEqdrvYglaK/Jay6hEN4nxQvXNHHhjN+GYswvBFEOoyurrWKZc1cfvw1W+GBoFQIJppNXDkD+E4dIAi0iZC9lwmtz1bYn7y8xjVfgLCEMkckWXpSX1JX7jjiuFajBi0dv2X9thTe7xaXs66tstm+6OHzbg8/wDlA/z/AIcX11jL5JXfgVBvjx3R1NqDGrEmtSfE4smSaDPXinhGk1Z8z+/2YcUEblCKE8hwPMnGBBWLyBVJcUqCQWP4vZ5DGNBD22JL0vNOxWyUsCMwZSMqfyA8fHhiV7ThFaVjJM2OybdGme6Uvbbe4ihHJmOaqfILnjms2kXXJcbeCOOAvICYkIqgyLucwteQyzxzwEm2+4W5gke8ZoXjL9OPRpjKgDSEIy8sI9i8j9Ge2hr2WYsQkMkbPEeTBQtSpamYJb6DiSsyvVQTJ2gLlEGQzIGVPowvf4G6AzcZEW2l1RoRmxU5AgEGlMTtdjKgG2pId71WUzxqkpMtrOahxKMkVXHDjyxnX9i+oJ6suX6aG7NnNBuhbrW0jRtPKdRcKTpC+wZY7fUbdc8nNvSnBfVhXWugUU8WPGmO6DnH3t1K5YZoXsBtztQVIoPYRhGhkYN3bt8m39wXEMGrpFhKIUpqCPnzI51GOO2GdlMoasopYpFmUEfiVwAxB5UHDGQWRN82S03F3ljBtr7iGNCkngGpz88Z1MmVCW3kglaKcFJFNGQ8cIUEVTVTGMfYW226HdL6U5sNJr/PI7n6lXHpJfkzzHwTpbc6WIPqzp7dIUfW2KKuQSJgg/Ik0kVklag8kOlR9CDGjBitd97FJumxWWyaiILmVW3ADi0EX50y5f8AMZQvsOJbaSkimp5I1ra3b7fcSxqF6KFhyUUyAHsGFVXBd2UlcSAWvTlYZzVJY+fHElgu1IY7Qv8AZbne2CsoohjCVyqPfzxXW6tkdqskI7w2uKRZFgQKqMenTh7BhN9JWC3r7I5KUgkibRIummWY4nHEm0drh8C0iOvNiVriqJWHS+liOKnjh0TBm9RRdLUDmM6+GJ7KldbK7DuHTlK1oeYxBOCjqFUuzMVFaimK1sJEE5CFjGZOfDFEA4bmMMQaHLOnDGk3QQJhXKoGNIGitdy9vRNW+tE4trnjA4HmwH7cE5tlIyV64u9x2oLdWrn8sgFScip4jB4JDkG/PFFJaiqS20ov9uf8DE1kjr4E5jCtRleAQa5sXcNnuUVtfwuOnexjWtfhlXiDjoVvyn/5EWsBSTR1aH4JxoP8w4HDWWfuKNSVlt2R8yKo49mMsqGEq8LyLBPZKaXNjIJrXx01qB9OWF1vEfA1kGba4hncUygvo+oo8Hp6hhWlMeLAQoTMIVkY/m2raJPNf8MLOJ8oYZvbO2u4rvbJ87TcIiUPgSM6ew54VJS6+HlB+pn9huM227pZbncf1YJDtW8cq6co5G9q0OJ67Q8/ZjNSi/QdI/MbfJ6oiDo843GWLUxNRH8gQTGBl6h/Mgb5e48x9xveMLbDkZEaUema3BoyHqQnyOeAl4GA1zszTqbuwCi9K/nWr/0rlByPg3gcZ1ngUH7BruLuWxiLJYKNbW8vxwSqaNGPLDa1ODMsiwCEgD4k/wCJf9mG4AI3KAyIlzbH/qIfUh8RzU41vlGTC/am1Wl5Ed9vY67UGolm4I+Yu04oP/tp/qHn8PM0rWqali2fgIbpuU1zcSTTPqlfN35DyA5Achhm5ESK1eXpDkg0ANAPHBTM0HNm3T0DU1a/ET+zFEybRPvbkOtV4t8IP7cOKVXcnh6/QZyqrnIQcxz01/E31Yls2JYKa6TkiSNNcIIYvy4lGlKck5AY5Hs+DpVPkv8A2lsoi7SgkA1dWWaR28WDdPP3Jhmm1IlsML2tmJ9tdSPUhElOfp9LfVibrg05PX+s7UtrDDqjdlWR6AAAnnWuIbP44KU5OWsDqjkKXuXAaZ+C0FVCqwqTz9vuxBKDpkTpcANqIdmo1eYGeQxStFAtrMF38yOxhoQ6E6q0Bp5eIxHakPRsgbJEbXf7cwRK5MrnpctBU1p4ZYGjFhdmUad2lsn9qtHjMryrLI0yq9CUV6EIfGmPR0a+tYOXbfs5D9hMJENcl6jLGDxy5HHTRyQsTGr44dioF37AqRXCDmSd8Iv9+VtILiEDV5FmpjnusnRr4AJBLAV/yjPCDibgwhaMCxbgooD7c8ZmQM3LaIdyg0yjp3Kj8m4XM+xvEYRjopzbRepfpZOAsslenKT+WygVLA+VOHHADJ9ibTEo+akBqXdB7lhT/wCrHpUXP+PB51iZICQAPxL9cg+wYquRRmPqC0hYZMQz+9qn7cK+EEhbwWO5wUaght5S/gTIyAf+U4W/8impYIEt0w2+6jQenplVXxLZU+k4E4KpZKX3j8xbdJNNI2jCxkA0pShpjj32g7dFUylXVk0ZWWJikvEOpII9hGIx8FWPp3hvlnCIp3F5br9yT4qeTYK3WXJP9aDst/Z7paQzxUAlVTrAqVbgV8s8VtFlKFo3Vg4Vt5Skh9PEHxxJYZd5QgXUZZs8uAzw6sTtVkG/1vGwXPwxmPRlB3qae3kaeOpEbetOeEdJKTBP2Tf4p1RgwIOTDEmmg4ZaheA24IOR4ny4YorYE65GWdmbUeFageXifPBbKJEhTVAQpBOdKZgeeCgNHgZEXUR6a4aSLQE3zaIbiymMC5lSTGPpqMGcHNfVGUVZrESizkA/rRNGfaB/+HFGsEZOWN3uG1NH8sxEUhqyDhrH3h54QMGidvd72+5W/QmbRcDx5OuK9pRJ1gtcN4kvTlU+icUbycYZPM/IjRXu5VayuoNzj+FW6dyBzjbI/RxwLYtI1cobhklhaa1Q1aM/N2R8Qf6iD35+/G2LH2Mic1/GZYrkf0btdL+Tcq/sxOcz4YyRHlvGEBUGs1k+pfEp/hiVsL61GKp3PDA+5uRlab9CIyeS3cQ1RN/mGWBZS/uZBDtrfHu9otbiU/8AV2LfKXgPH05AnDzxY0eCZvvSW4jugaw3S9CenJuMbfZh7KQIHSXb9NJafmQHRIPLhiafkYh3F9JAJFQ0K/mQt4eIw5mB7DdIjuM0TL0rmd+tDPykyoVwX/qAtUdws8IYZSLkR4HBTkVqAh25tMu7XsiOxg262Ak3C4HGNSckSvF5OCj38BilKz9hbOAzvF+JCkdvGILaBelaW6fDHGvADz5k8znh2xUit3t6ADEDw+JvE4VsZIB3k+deA5eWCgNC9sv2R866Ach9mHQlkGrjeHiiAjo91IKqOIRfxHy8BzwNu3qvqbXr7P6AqGGNAaku7EsxJ1EsxqST544W5O1L4JCFgMsvIfvwDGn9pGQdjWSsDqaW4KD+HqnP6a46k/wRz3/kyTEs8YKq1FbMj28cSZg5s21wyLSaNWjpUKw4nljKqYGwKz3Ftf3EV2emeoA4j4AGnTrTKlGAxx2TTaZ2VaaQzeCKKOpNEBAQjMnnSuFdmh0pAe4z6qgkaBUuBmPpxKzbGwSu1e3Jri/+amVhCVrEGrmAfHzxfVqIbLmo2AKp8QAAppOdfIY9CqORsb21nWeQkZlqMtOHnh6YFsE5JFoRzxRsVID7k1FND7sIx0Y73Ffrd7xcTFqRq3SjUZsQmVfprjls8nTVYBgec/CBGnInNjhRhaQoaMwqTxrxwYAO9I14gLypngNBkZNpG0qu0dRG2pARwYilRz54Bj6E2tQI5h4S5/7iY9LXx/j6HBYlHkfMf+bFKgYiIarSIc9Az8wML4RiFvMBIaYfhUE+QJ/fhbrJbUwLtgjJkWRsmNQDzCEE4Spaw13xZ2l/tkDQKFlQtpFAMqf+KYT2KK1cDerZ1bkzeaJ0Jt5k0uBkD9WOFYwzvecgW9tAciDq54zqLINs93n2K9EwXqWrHTcW7cGXxHgR44FbOr+gtq9kXncNshu9stty2xjPt94AYX4lH+8jEfe5Y6b0TUrgnr2Q4fJV2injkoylFUkGvGvhTEIhnQ3JIhLMADw54dMEFc757bvJ9vku9r/9yo1TQ8eog46f4hywQNmZbfuDW7hg1PP9+Dasi1vBdNl7gjnTpM41DKleFcc1qtF6WTLPYzO6CGTMEghhxywFYoyxWiRiIqAAxzLHP/E4vUhZnJYAwpSq+PPDQLIKnga2k46Uf4G88KhpkF7ntyqkM1vH6YpQ7og5E+o09+K0t4OXdq8oG3G3r02y/oy/UT/twCCYEv7CW2mneBiki0kRl44DwMH+3O9zA6bffPpecdS3kPAsuZGGVsQJapdrq7tN1246CCJUoV88Ut+SJpQwBDeSmyjkGd7tL6XHN46U/wCJMsatpQzRNiMc4ktkP5U469q3IVzy9hxJrlBEukmmO6J9S/lXC4V/IwE3iykubOfbVqJUInspPwupquftwiXgJXts3K5ttx+ZkXpWe6Mbe+jP+ncrkT7zhl8fIC1RI0kU233L1kpRCfpVvpwavwFkCK8D0L5GUGOZfCRMjgxn7gBl3dMWVDmYyUPmMOgMFbnZC3jDEk2Ep1xTD4reU/8ApJwrRiw9ltuW/XsO2WYDbsTomVjROmMzM55Iq5k4alXZ4A3CNYvUs9tsI9p29i1rAS0kxFGuJyKNM3tpRR91csdFvhESq7ndGOqjOQ8/AYRsZFau58+OXj4nCjAa8uJDkp9NcwcFMzRJ26QtSi1kA9Cf+o+Qw1rpIVUbYWihf7zFmY1YjiT7fsxx2cs6UoJBjCrRsvEDjgBGZ7tYkYqK6QTQZnhjSY3WGwhte1NnjhAKraQ5jxZAxPvJOO7YoRyJyyJbKsjez6/ZjkmSkE758WrdPjJyQfbjdoNAqOyNzGHjcB5pOrdH8QA0insxnSTK8Ajc9vlWWSMsVikFY2HIemmRr+IVriVtbK12Ag7e5mmgsbYzyOlY7y4OmNMyNXMlvIYV63wg9l5Lf2z2/PZ2UMjXUk9wwPzin1IzE5GMH4QvDzGOnVp6rkjfZLLJbRSKdOin8Q4HzrjorUk2PGBeosrZFeNMq+3DRAJOTlSppQnAbMiu7xKyRtTkD7RTE7MdIxyOMMOqVpqqSTxJJxznULCKQBStfDGASAjcsgBy/fjGPEIuRyPMDNsYwjSfwUTmtRqONBje7Gimdf4w3/7aj/049CmP8fQ4WPyNSJmXitWH+U6sOmARaNVJI/8AlSMo/lb1L/wtjIzEbrQWEpPID9tMa6wPq/kZB3jvu57bu0BsH0PbCufBgeIYeePO27GrYPW1alauQr2V31tncM52a/VbbcXBa3iY0SVlqQI2rx8sV07ldw+SG7U6ZXAvuLbVmVnRaTJVWyIK6csDbrkOrZBRZ9QYpINLLUFTjmTOllf3u1eaGTRmacMNEgFfo7+oUexdyHtXuIj+ybu4WGSQ0WK44Ia/d1cMW0OMPghvpKlco0Hv3t6XbpsvVGhqkmYOluVP9uN7FID6+zsVq1dF1M5qAMhjnR0MWl4GJAH5Z4EnicOmCCnb12Vsj7i950DpuGLyIGKrqPE0HCpw9X4IbqvlA6XZrC23DpW9usQeElCozBXPjhuqbg51drKJm3bnPAkQnNY2FQ3vpQ45dmvq8HoadyuofJbrDdI5Rk1AeWBWw1qhKKdXBHHnXFkybQ3uCRzwtA+ZGanwOBYNV5BCTBaxn0uvxV54yGdZGRBHI0yE16y1HtAw9WcW3V1ygZc2yOYiR8aFG9owzJIpvcFmY7a0uBkYZwhPgCdOEXAzCfa2/wByivFKxJhcxt7uB9+HqxWiwT3y217Ff0JgmHSuQOFDwY+w4KwzDkd/Lb67WIUe2JmtvONj6l92NdeQEiKWeeYSPMUtLkeoD8WF/wCoQcLu6n6qW9WigOlmdqUBOWAkwgG/VA91bSgxm5cVFagTD4HU+fDAdTBTad3k3G2tZ39F1CxtrjxJXgcZ5yZDO5yiDeLmCtBcBZU8pAM/pxRqUKRIEeSbqsaFjqSvAnmMFAJaiSVxb28DXPzLCL5NBqdpHOlVVeZJOBDnBjYO0ey7PsfY5LT0yb/fAHdbwEMY4wapaRt+CP71Pib3Y6a1VVBG1pZE3WYRgt948MKzIp1/PmzE5nE2OiubhcUrTj4DGYyBQM9zOsEKapH4Dl7SfAYR4GRaNu26KzgCM9WOcsnNj9gHIYk3JRIfkvo48kGVOXHCyGCFNdl+dB9AwAkOS4J8SPCv78AxsvZfey7p2ZbWTEfO7cq2k6niFQUjf2MlBXyOOt7Jqc7pFida37B6qakZA4ggsfmnMravvkfFjMwW2ud4kBY/4DD1FsD7i6L74Vb4OmQRyq+Zwk5D4EsRAfyz6FpQYJi17JfB4l88dFGTsg0COI4HFlYnBx5FKnPGbkyQLu59BJ5YjYqit79usENpNK7D0qaeZOQH04laxStTNFiJWpAI5lshiZUcUISKer3UGMYdEMjCpPppwGQ+vGMc0qgoB7hy9+MY7zyA8/8A82MY2yyu0fcrqIAiio/DKnUkjrXz04708s4msExJIukp4qOJp5Gv1YZeAMRauNDtoIoI1auWegePtw08gEzmC9iijDikhLAVBro5YDcwNR9XJkf6gWYfcTMgrGrNG1MwGU8K88seb7K/KT2vWt+MGbbtavHKssLNHLGweOSMlWR1NQVYZgg4g15Ks0H9Pv1MtN83OLYu5SLfepR0rO/+GO6JFArDgs3hyb247dO7s4tycG7V1U14H+9u3HsbrpqSXYag4XI5nA3a4Y+nZ2RUI1qxTRQ8DiCZdopvfPaYuIHliX1j1BhkQRnUYdMHJpv6Td/x969pS9pb44Pcu1Rf9NM59U8aZK2fEgZMMdNbK1erOS1eluy48gfc7K7sJ3gnUhwxCilK05+zHFarqd9LKyki7c8jzUfjUgk8j4DCpjtBeexR46MtVYUI+3FSaZVt1s5LPcbea4IS30uhmchVFQaaieFcPS2Tj3aeuVwRLGCGeCMIySq3VUhSGy1VHDD2WSCYi3+ZsirCpjzqp4imOW+uMo9DTu7YfJZttvxLGH1Cg5YFLFbVJsZ6+pTkBwJ408cPMgWCNfbazDqIM1FT5jG4DJCtmRmoT7MaQ2RJudsDKjrRdDah+E+PswybOS+leCq9ybdr2ncY6eqP85Pd6vswfDOYqtiGXcrkLwuIUnUedM8EyLPZXHXtHtnzDrzweUYXBOXtkldqXO3tpkU8WTh9a4pVygMlybjaiMwpJqRvzLdh550xKPBkQUmWskkEbDX6ZuVK40jQRN2ggXb5RIpa5E8ISQnh6xhWZitjX03Eo+9fPl7BTDCog96Xgh3hEB0yGJJI2PAkVFMVqKQbXuASnpiNmLfFGoqVbxwHgxuX6WdnTbLtyd071FTertD/AGi1bjb27CnXcf8AMkHw/hXzOXRSvVT5JXtOA5f3JGp3Nakmp4k4DYqKpud0XJJNa8BhGOkVTdLjSCa8eH78KMV52LOGILVNFA4sfAYVuB0gnZRfLqxAAlk/qOPL7q+Q+vELWkoqjssrn72XPnhRhh3bT+84BiO9xSqke3xxjDEktBxoDz/fjGHNv3W7265FxZyGOamllHwup+6w5jBTA0aDsHd8V5H6gYZ0p1ISa08x4jB7QI6lqsNzSdxVq8zgq0iwH5LtFiUV5Z4pIkEDqJLfxufi4H2EYR8jI7cSGPUjZihocFmJ+y7gI9BByI+sYalgNFwg3GNoga+3F1Yn1ETXQUmhy4g43Y0Fd7l7hstts3uLlyAMlUcWY8FUcycJe6HpRszW83e/3KYSOvSgrWKI5kefmcc8nSqwLS1J0tIczzbL6BjSAkuoRaHKvw1/cMzjSAadHHrc0Byq+X0KMYxzS8npjUuR95sh9GCkaRswSdcRdQtcHOlPSopXh54MAk0g9x3syyX2xPBeJKucdaOACWAzzyLHHUrzmpy9fkE2/fd9NK1vuPV2y4XIJIAEamXEYRbXw8DdAope8XXb3J6uRMZfUrUy58cVmRRVvcNbenT8tcKag8Ub6cbgKIHcO2i8iaZhVQPUeQHHIDnXEttJR3adkcGXbzZdCZ4nFQDlXHA1DO6ZRS9/2brL1I2KyIao6khlYZggjmMMIbb+nHdn/fvZctjupDdzbMFhvWPxTR59K4H84yb+IHyx6FL/ALK55RwXp+u+P4srG9WclnelHUoTny8PLHHsUM7aOUQpehcR9I+qoocFMBnPcm17l2/vEO+7K5gvLZxLGw4VHEN/C3A4ZMFqyjXrfu7bf1B7Yi3KL8ndbeMRSw5Aq65vG2fn6Timx9l9US0/i/8A1ZXYYpI5CjLoZSV0kEEHzxxJneywWzI6KzHUcg3h5Dzx0VZzWZze9ottxsZbe4jWaCVSkiHgQcayNWy4Z8+dybHedu7q9pIG6Bq1rdCo6kdcsxT1LwbFqWlHBu1ujjwItN33mMAxXkqomdWcsgrlmGqM8FwTVmi99s9xw3MKugC+oLcQqckY81r9xuX0Y4tlOrlcHq6Nyus8l6sZxJ6q8RkBjVsVaCZ0LFmfTzOKoRwUnuOSXbblLmJS9rcEgsuel+P0NhYyC1+qyMW/cjOoRianIKeZ8MNAv7ahRrLqwRh6N8xEySUNRXPLLDVRw3tLbM/toTDuNiH4r1bOT2qTTAqAJQAxEeKMVP041WMxd5HIj/ORGtRpmQfeXD8CjUEUSsAhrFKNUB/C4zpgtGCmvUoYCizIaj+JcIEg7wC+3XDn4ljSUHzQ1woBnt+Z9FzEqlunddSvisi1wzAkTN52Cy3i8juLt2VIk0iNciTWvHG7jdTRP0o/T3br2X+73Fqsex2L0jjIzu7hfukniiH4jzOXji+jXP5P+hPbeMI0jfDLLK88jV1Zk4tY5kUrdZia1yUcvHEx0VTcrkAMSch+3Ctjoqd/ddSQg1OfDnXAGQ5a2ZT82UVkOWXBR+EfbjnvaS1akl20rkCc+X24lI8DLyKAag8Kg88aTQRnLGlKgnPLGANuhZ9KDUfiU8cwcYx02hzaU08hmcYBwIoyjSnnzxjDsEs1rIs6NoZfoI8D5Yxi27D3HbyHUrUOWpTxGeFWDNFsO9xuoIb4lqMU7idT1puQN6przGArZN1DV1KJIq1rT7cVFggbbedKR4GPA6kxOtoHaLLabppTxryxXtgTqOT71DBEWmcBAK6v3Y3eAqklI3MXG8bh81cVMMNVtIeSg8WPLU3PEnaSyrAtLNVOQo3guZ+nARmxbRxxniFJ409TH34eBZG9BOaLpB4u2Z+nBgWTyW8YbUxLEcScMkBsRuMwhtjIoOpPg05AE5VOC3CFWWA+qnSJ6nqOeuudeNcIULVuva9/bSJe7VcdWBv6Mluwz8PVXDbNFlmpGt0+SDuHectuq7d3DY/OaFIlNNEwrwIfLhgrZbi6N1Xgf7eksbxCdm3BiAapa3A0un8rjjh6JPhgt9Swrue8IDb7tYO0IFEvYqNQfxUw6tZcoSEcst3NhLLa3lzBNtt2KQTBtDRycg1eR+o4PeOeClGCO4dg6qsxXTTNaDIfvxHZrk79ewo+57X8vQuPy3qVB4jHNZQWTkD7ZuN92n3Hb9w7cvVMVY721rRZ7Z6dSM+eVV8CBhqbOrkF9asoZqndUNnvexR9xbO4nsGSNtaj1CJjStOTIfSw8csdO2vZdkQ0vrbqyhaGibSzEPWtDkAPMjHNwdXWRe47X81tzM6ArTMmg4+Rzwy4FWGZ2pve2Nxa5twRazECeMGlRXj7sB5Esurlf1Ltb7y120cjnqa1B1U9RBzqTzxFtzkpVpqUHraUGhQmgHDFKsSwXhulKBGNQeQ44qmIqlc7z7Yt932qe0YhJqFraU56ZKZe48DheHI96q9YZkC7fNZhraWNRJEv5kNSCNFSa6gtfdWvLFFaTybVacMjWNwYtwjuYG6bNqDqfTGyEiq08PtzwWsDU2OrlGkbDvnUj9JPpByPHLOhpjjahntativWUW6xuGvI0ZDVTThwzxalibUA/vW1hg2O7LDWmjqpT8SZ5e04a2CWxzVmeW+42xjoTRScmIHH34fB5zZNiubcEaZinmAy/swcCHXjsJWDGjOHEqkGh1D7x88aA9mLYK2qSmTmuXP9mA0MtjHIC+caRtNxqFBLAeYGJbPYprX5tIPcaaJrTTHLG0QMyvEJAVqCaGlcD1/b1bMVshuyZMCEKv4Vdh7jircDo78qHTQ661ZNDBuBHswkjQLVFiQKoCqMgBlkMAwc7M7Su+6t6FkrGGwtwJdyuh/pxV+EH8b0ov08sX06uzzwJsv1RvUa2cFrFYWcK21haoIraBcgqAU+nxOO1s4+QfuEYeNlPwDCsyKB3BGUZtOSgfF4DEmOigbvcO7lVyH3R4DClED7WyYHqldRWuTDwxz3vJatYJtAki6FIRhVhy5Yi2UI8qswIqatlTkF4HhhQiY7WaSWiJkgoXPDPwrgoDJC7YgjQSlmK0LAGgqPrODAJPOhHpjWhPhjNgG57YQtGtxWNpDpTXkCaVwEDuhpwq1WNdTfiOQwYGI0lrLIauc/q92Ggwj5cxnUpKsODDLBgw4d03aIARzMacAQDheqCP2XeW6W0ym5txKo4uh0tT2GoOFdTFwtP1D2t4aSCZSRmpiaoPuwezB1Ilz3dePKGtNqnkpmkrusVfYp1NhWMqhjbd97pu0GmwitVPxSzSFh7lAWuMrMPVBaG2ldhLeTG5lH4vREp/hQftODAZSH2uE+AKZDyC5LhkhGcCTMKyERqeXlh1UR2OMEXNVr5nMnDQLIy8lT6j/sxjHhMKU4ftwZBAhp4cw2fivGvljdjdTv9vDQdb5ILAnIqNTVyyX68aQwyN//AJ135BpVIWAQ1QRy0UHyGK/8fYiP7ahMWHcVwi2nc/bcl/bocr5GXqKB4gGrYfrZ4tWRey8MjXnZtrcw/M7JdBo65x6tLrTxpnib0p5qxlf5K9e33c2xRuBfTJEOJLll9gBriT718jqGVS/3vfd5YRdV+gprJI4C6j4ZDIYm7N8jpFp7L7/bb4zsu9yPebZURret6pYXbgOZaMV4cRyw2vdGHwMnBZu49rqiBm6kTkdGQHUCDzB88PsrKOrVYpFzZMEYadS51bkPacc0NF5Heye7T2veTWF9Vu3dyJW5XiLeR8uqo/Cfv+5uWK6tvXHhi7dXdSv5II9yWhsLxUkWsR9VtICCJUOavUeOF24ZXU5RHtLl5UKlqnwxq2BdQDN82mK8heM0JIrXzw5JMrO3b8+yW77Pu8JnsFNdvvlr17Jy1WpT+pA/3ozw+JaHiziyhkbVdX2r/VfJbNuvJgF6ildaq6niGRhVWU8Cp8Rjnh1cMumrKUHLW5FQeGXHFK2FaJ8k0U0RTiw4YeTVRnff/ahvYjcxRlp4wOpGKUkVakceYxquGT9rT2XZcozH+/LG+qGJC6klXQaaVHACtKDlli3U8wesO5dys7xbuupA1JIqUqCa1FMgfdid6JltO10cmi7F3/s6Qsy3Uccb5mFzoZTzGk/Zjn6tM9FbqWUyB+7u8brfelZ24dbBaPrIOqYqfSAMjp1D3+GKrPJybtqeFwA0d6ENRQxPw1C14EU4D6MMc8Ei2VpWVYV9ZoulvUtaUyJxhWTodobQXaZo5akMgYrXI0+LwIocLbZCFZp/Yn6TrfJHuG5F2jct04myGg8OB4nHj337d7/B9df+rGS+TWNs7N2OwiEdvaIgApwqTQUzrilPQp5z9wj9/wBtbXeQvDcW8cqOPUHUGuHt6dH4MZ53L+lS26yXeyuYmRRSzerxvTlmarl4YlV7dOZ7V+Hz/mFWaM8kMiSSRTRtBPE2mWFhQqeVK8QeRx6OnatleyK1tJ6ysL/c9yt9t2+My3124jgiHM8Sx8FUCrHkMdFKOzhBbhSfQvbvbdj21skWz2Z6jg9S/uqUaecj1N7BwUchj0IVVCOK1uzkkzGnpX2E4DAQp5ARp5YASqdxWqvG2nKPNieWXEnyGJsZGX3QS5uW6J/IB/q0+M+I8vDHHsvOEdVKRye6ZCnMlfwjhl40xEqc+WuJGz9IrU1/xwINJJis4EFWYyMKA14CnlhkhWxxqUovDywwBy1265u2ARaR/emOSinEDxPswsyK7QFvl9o2OykuZTQKNUs8hqcvAfZhHjHkm2ZX3L3NNuO4fModMFStqONKGhbyOWLa9ULJPtktlkFu7G3uUX0zRrJXzIw0HSnI+NrlehA+zACLXZSTmNR5gfvwAjsfb7sMxTyGf140Gkkw9swVzQAc6Cp95OAzSEbXYbKPSdIBXPIAn6ThYDITjtoIhUKoI4nifrwYBIozgmkaaj+KvD3nLGCKTVJnI5Ip8IwyqB2JEcixjIaT9JxRYJtyMS3IY1Y1Ffd9WBJoOGcsPQCfHzwTCFR3cAIWPJeJwIMTLfZbuY6T+WDmStCQPacsAIQg261tmC26de44FjmB5k88AZIIfIXAXWzj5g/06jlzAHswYDKNDUnxx7R5Qo5ihzB44xjPe4ex2gubm82+RoBN6iEyox40x5+/RDlHRrv4Y3ZdjrfWAa+jE9wuRc+I8sauuVkLsVXujsv5SKaSGMKUU6QooMc+3VGSlblOi7PvLe7t1dSUiKSzGnF3Nfqxz7autR+w5s3eG7Wd9dQTwPedua2+Zl4G2djXUjHl+JOfljj9HfZU/L+Jte3qy5X21Wi7XHfWr9ZWUNEoWqtGwBAKn4mNefw+3HrWqkpR2U2d3gzvdVt5XlUJ042JpGTUr5VxySjsSaE7T3HNY2R2fdY2u9pH/tZ1Aae250Wvxx/w8Ry8MHtiBHzIYFmIoo7qKQTWU4rBdxGqOPDyI5g4VYC3PA7rUCnEHFEyTRXe4dqiu4mKga/HDyAqG2b7uXbG4xuQ1ztqkrNYsfToY1bpV+BuY5YbkWINYdbeeytt42qX5naLxdcMo4rT4lYcQynIjErV6lKPsvqQ2vZ9X5J9Q4jlTxrgSUVfklxzG6ULIasOYwycmsoMp/Ujsk7fK+67eh+UkbVdwLSkbH76inwtzxfXfwzzfY1f+SKjbrrKqq6iOGoA1+vI41jlJvSAWjJRlzrUUpwFMq1HvwkBJNuJmAFupLEgCh4sxyoKDjjQE0PZf0z3yW3guLzRH8yNaRB0DCmZqBVtQrwpgOtuEL+wkX/Z+87XZyXFxYSRKiEwpPA8RBzJYP6SeHEeOEdbrlA7SEOwe35Nx3i3truEvaqVuZYQ1QWQVDE55VPDHne5d3a1r+v2DU+g7C2W3t0jRQKZKo4Dyx1adfVQhmPmvj7sVAeXTmCp4ZHC9voaBqZUZc8xwwGk0Eyn9X+3kSxbuG0GieyQrdqo/qQA5/5k4jEEnrsmuHh/9zVcMOfpd2kO3NsXeNwSm/7pGCqPk1ratRlSh+GR/ifmMhyx72unRfUTbs7OFwXN71BkeJ4eQw0k0NTMFXI8cAIOuHrUcuZwDGad19xHdHbb7Bj8gppPMv8ArMPur/8AbH/F7Mce3bOEdOvXGWBY9rmYZjSvChxDqy3ZEpNsRPiYn2cMHqL2PPHCoITM+PhjQYYEQ4BTn45ZYASXDttU61yvoOVvCK6pD4mnwr+3AJuwUlngsLQTXjLGWyjSoXhyVcFfHkRuDJ+6e8LvcrxoLqE2yRtrtlYldIGWo19L1xWmqMvkm3JV7q41gNHU8akkUPMEAcDi0GNc7LaK47asmVWVI06amSoNR8R8xU5Uxzy5Z014LAtuppzrzPP3YMBkeWBagHhyB8fYMYA+VjjX8whQOFeP0DACQ7vdrCEVlmWNRyJFcAZVYOfvbttDp+cUnw4AY3VjdWPQ90bDOKrdqc/vGg+jB6MEMIwXtlPTpXEcjEelQRwweorkkGeJFOo1I48gMGRTgu42XUWqDw8MZMEHo5GkYrCms05DLBk0Ey12u4kINwxFRURr8XvwvYZVDMFrBbIFA9ZGSD4vfjSGCSlpLKv5hEcR/wBMcKeeNASVbxBRSBD/AAkj6wP34IGLKIrABi0z8ZBSi0zzJ8fAYxi6Lj2TyxYxjHJYlkQq2YOA1IUyPalraV43H5bnUrD7cRVXVjzJnXdO57na7pdW9yqvaSMTG1OCnhjz9221W0+DopVNAybuW1t0MlxatIlF1lBU+nnhX7KjKG6D20bh2j1mubaONYp/60brpDBqEg+BqMGn6/AlqMfte6+2kXcth3CzmGy7cwa13OFC4jSRa50BqA1RwPmMW1Xq06NYqTpe2tyjOt22faZLmW42rebe5tZJAsSNUTEHOpjANB545r+vnDwenT+41a/JAO4sXVmjEsMhBpRXWv8AumhxJ0si1d+u3DObbuO5bHLJoiMtlP8A+6spARHIPxD8LjkwwqcFek8BrrWl9btd7VK0kC/17Z8poT4OvMfxDLB+wY+QdPKChr78MmK6lZ360ikhYnieGCmKxrsfu657auZbK4Rrnt+8YG9tlGpon4C4hB+8B8S/eHnTFeUSThyXy/tks547m0mW4sbhRJbXCHUrxsKhgfP6sc9l1Z11fZSdhv8AQRpHrOSqPPDKxnURu/WNu4uIllhkXTIgoxAbLMYok1ki4Zju4bVFt27XFki/lKepDrJoEf4Rln6SCM8PMnmbadbQeeTpjqS0kK0FQfUDyFfE0wUhJN6/Tb/4/blLbWPcG/OkE0iLNa7cVYsikEqtxXmwOYThjqp68ckbXNDTtDcYtv8AnEtZo9yMrpC1o0AZQ6OBPIXWr8QrLQZcBh1phfUUHQWyX1ncWN7cbgu5qrJdzzEB2ZdS9HU5oY2QV4fXhOk4fJpGP01tElu903ESrcB5EggmVVTVHEgAaiemp548J1nfZ/YrTg0VSwFF488di4GG61ZgRwFa4knloLOkV0srUp9Yw7rMNGTGZpQTQnlUeGXjjTmAACRbe/u/nboCTa7GQfLwH4bi7TMVHOOE5nxag5HHR62mX3fC4+/yLe0YOS7k8spkdtTMST5n9wx3Nk0NNeZ1rVj/AOK4WQkmC8LDSTXLj9uCYpHdHcD7qzbdt8pTbuFzdJ8U/iiE8E8T972cebbsnCL66RlgiG1iiGmJAKDicz7ziBUW8iR5E1IFaeWMYiyXkbpq1qyE0UIdRJ8BStThZNKH4tp3K5XUdNnFxq9GkI8aV0r9eEbYjuV1Nymt+8INthaTcEIKPGaUVz8LZCnpwuuzfIrs5DvdvfO0dqwPCSNx3kiq2MZzTKuqYiukfw8TiqzhCtmN7n3TuW63/wA9eTdWZuCZ6Y05BQOFMU16+orI8u7JdRaLqkqoToAI0k8KsfiXLwxZIxC2u0kut0t7WOssdxIEZY6alH3iK5UAzrjbH1rIaqWb3s9vHb7bb28C0hhXRAOLBQTpqTzxya22pZ0vAQFK0zLcwuZPtOKAB29d0WW1xsoo1wBlGp4e1sFKR60kzrdu9766VkkujbLxAQVHvOH6FVVIqe77hfJMYZpzIzANWtcjilUiiUglpmbmScMUVDq3NwPRGzE+C54IWkiTZT9xQzD5V5RJyqxxiVoZZdq/UXf7SiXDicJlJG+f14nbWmMtCaNS7E3zYe5mKiXRfp8dk+R/mU8xiNqQc96OposdlDboCSIkFBwqx9gwCZJijlcUjUomVWPxH38sYI9HHFDQopmlPJQaVxjC5JVRwkgeSVsyiD0r/M3wrjSGBfWNVSRunEfSAOBPt4nGkEDKzAO0bKFBYBHrmwpU09mBIS9qce2eSOA4xjuMY8aHjngGB27bVYXdu3XhVyBkSMT2a62WUPWzQD/7a2lUCiP0kcMcf66nR2ZBfs/YI1kEduB1PiXlXCLVVDdmR9i7d2fary4WXU1jeRmKaNzVV1fephtSVH9GJsyjEv1J7TvO3N4uUWBm26c67HcEzRkP3VkGVRwphNlerJJlEKxurvJcaChqkTBwW5cc88sTkJLt7828kcQuJVJA6jBpAFrlppXOnHAgZWa4C9tefLzR3sF1Is6DWCq6KE5EF6tqXy054SB/3X+WF5dzsr2FpLrTb3Z4NCv5bnL4kJ9Bz5GmFdTr1+9GLKQbPt6XFFjvIZaivErT/eFOXjgKS/8Aydb8wQJNj1BdEiaSaEg5ivM1phpEe+kFl7fSLZ7Y2cyvdbTMdcsKusht5XNOpDwNT9+MZHlnjNzyc+r2bVt9CXeW77Zdq3peGWoguBmrCvLz5EYnwz1k+9ZXApZmdSX+HmDiquI6lI702edtxtNxgh1xPbOlyzJrVNEnoY+FQ3HD1ag832P5Bn9HLDtJu7ornuV/ybaPrbcBGrRfMKw9UisGLaVX0gDjjp0WrVyzlvMH1htvcmx7k2uy3CKVcgEroY6gNOT0Y/RjsV0+CJMSMrHcxxvWUliASci9WHM044cwxeP1NruGjg69w9qzLbEqrsSholTwqcqnLGMZ12Paw7ZeblYo6FBKsqCMhkAkjViFZaKwVqrUZVGPmdmr9XsWr8wy9coufUSoo2Z4DHR2QTzO2mo9+C2YY62ZBqVxOtmFoFblM1xcLt1vL02kUyXc/EQwLkzfzHgo5nDU0u9oTx5+xnaFIO3C4iYIkEfStoFEdvEPuoP/AFNxJ8ceq2lhcHO8gh71oiepQE/CPZy92BIUMJuBeahOXFj4YwwE3numG7DWNtKUshlPMK1mP4V/g/8AN7Mc23cuEX16nyxmyDXUf/RRGZFB9SCiCnIsfTiDuO3ALk36Ib0NlMsUd2VDawxZBXPSSACWpywtbyJ3DU1ts9hZSXd/J1Y4gWd5Mk9gQZftwt2BtlT7QnvN/wC5LjcLSH5azXVDDCoADZjPlmKYWlXMCotfeO7w9s7eWuWDX8qs0Fuc6KozeTwAxrvPVGbMWj70vrYXNzY1jv7qokvwPWARn0/w18cUppfkAEmu45JGd3QuKt1dLa3LcWZydVTjpqkgEdpDUlpC6E0MbU48QSQM88OkYZ1oDVaGmdM6E88znh0jF27B7fi+YS+1ia4bJQvwxrzz5scce6zu+vgrrXk06+v4dus2ubx9MYoEhXiSeWCvgvSjswVufdoMSR2iECQD1L8Wf7MN1K11xyAIrVHcm6TqzSk9MsSR9Axm2K7g652q0vCmpFV4yWdUFNQXxGGTArlevtnmuFe7cBYiSFJyNBwGK1Z0a9gKO3XD0CUC+Ayxux39US7SJrQAAVYcwMHsSto7EwXMpDKkeguKFueB2E/4yREe3ZBkoPiaY0llQbtrm72+8ivbR2guoWDRyoaEEY0iX1n0p+mXett3Rti/Mr//AGkApOoOTkfe8c8RsoZ5+ynUu0iyCMl2VKcEA1Ef5cAmiLJe9KSOPUERqdWaRtLVb4VVQM6+WF7DKoie9jgaq00ngx8vI4DtBokEbj3FaW0b3FxLHDEvqaaZgqA+1ssLI0FHk/VvZjukRiaWSzViLjcypWCPIhdNRqerUWoFKZ4E5DB9IKce+eKLBxjCgcYx3GMNzgtEwHhgPgKBPGOtMxjiZ0IiTtpz8eOFYwNnesb14lfsOJtjFY7mgsksZ5bq8+WtlWuhgskJapzMb5V8xngOziBba0zO5+1LncQZ9vh2q5SVjIsiB4X0HLTpNRiXZMX9bBlt2HuKS3Bm2iCfXE6QUuzVJSdQlJIz0rlTDKyN+uwqXtvd/VEu0xRRBgGSO59QAyOZqCT7MRkb9THm7e6eiP5abpqCQhuUdhXwqgFcszhu6B+qwzDY2oQLOkinLUEUZ05EnXhOyD+uxHDW2lurPMGSmhCrBMsjWimuQywcA6v4EMbF2UNcNpqxJEWoknMDPSfpONBoZKtN3S1iazRxcWkjFjBKlQGqBXSM1anDSR54DrJbVuvreCeu5bFK7ERSF1ChYzKoj1c9RI1UwOhZ+5aOCG7XE0zvJ0nbVSP1hIwoqAo1ZaffXBg5LWlyyNew7dJNDdPAYpxRnkRDFp0Gi6QDRgTlxwezFCdtf1kikUsXCkVRgwKgkhamigCpNSTgKTEm13veLKeOazu54nAVXIkeVV08S0gJdyOYByxVbbTyDqi1bR+oN5CJ4tyAvrNyShkdgyKwCyFHB6ifi04tr9prDFdCRtneG1XncUfy6C3VraJCq0VAwq+kZ8AWZfPjjyv7pb/7K3XxA2rGDR0ZWVZBmwGR4Yoqp/kuSk+B0uHovvpiszgBC3G8S1tnkIJOQVAKlmOSqoHEk5YefCBAKn1WUL27kNeTsJNwkFCNa1CxA/giBp5tU47aUVKx58iWcgqWb7xOQ+Gv7cEBX99vo4oTI7BacCTSlMLOTFWkvrvdZBZWqOUcV6aCjSDxcnJU9uI7ds4R0Uqlllh2rsyCFUn3NhNLkVtlr019vN/fl5Y53WMsz2Nle767+NpF/Z9mGqZgY5ZYh8IJoY46ZBiOfLC8qXipNsFdv9s2m2wx77vcmg1/JZ6s7uPuxDi7U4ngMSTdngMJEbdZNz7s3mG0iiZdrQ5R58DlU04ueWC00/qBZNEmvdp/Tjt/oQxLNvzwgxWuTC3jJoHk89RFeeGduv4r+T/0C2Y/vV5Lvk0lzusjXE8pDyNqoAw8KcvLFNOpVX1HrT5K5cbRCoYQSkBvusPtGOgzqDZLG4SooWANRwzyw6YnUJ7fsN2li00lo09xdDTaQ0+EV+Mk0xu2RlUJbX+nNzIUbcpxElamCL1OffwH14Z7EBUNC2qysdmtlgto+hGa0AJaRyOZJxz2yVqind/b6bnpWsLlVjar8a6vbhqUg9H1qxyRNgsy9wIr3cG0yKAIIjVhX8XhiiWJJexsUwiyLEIZFMU2iSFOkiHMHz9uI3ZzC0i6CSbmzB3MZhZKUo554FXODAGCG1e+gXcmKWpbUxGYr4EY6UPUD7xNDFvFylqB0A1YyvhiZ7GvNURnkkYg1wRh22RpZAAc8E0BiXaZXg9BDU4gYWR+oCu7KeJjUEDzzwQOoa/T3uW42DuOCcMRC7BZQPDnT3YDOTfrlH0wu625iF1C1YJlqpOYIOJNwed18ADfO7rDaoDPuF5HbRn4DKQCf5FzZj7MJI6RnW6/qhuV9IybDZEIcvn70EAjxSLj9NPZhXZLkdUZXZbK93S5FzvN0+4Tp8PVP5afyRj0j6MTe34KLWT/AO3J0tNRpp8AAp78R75Gg+uVOPqj5wWDjGFA4xjtcYxw5g4xgW6lXceBqMcl1DOirwQrmhqTiTHQLuiFieQn0AZg+FDhGEwT9Q96ut33h7XWUtIjVYuR5hjjz9+6MCuxP7N3W3luIbSKQ9eP0kciuJa5bkNS63DqyxacmNcxlyGOtlkQ3kVFIBoS+Zp/FhRiHIgaQVPIZV8jhYCDpFRgWC0GX7MCAjbtGVaPp6xTnkPpwyQCOkcivqgt0yz1lQdNONCcOqis9JJdtQyqrljqAAyp44cEHVVdZJhWlCaBQfpOXHAMcWC2bN4RRsssl8eAwYBB75K2YkcATmeHLjqxuqB1R2S1c6mWUkvlWQAkgLpHnkML0FdCLJZ3EYOiLUKcQ+Z86Mcj4YHRiurHo7qSNn9JVWGRdBwHHVU04nAaYIGpKG8W4R+gWA/MTILpzFcuGrjhNtFevVgNc7I7qhv7Jbe4al9CAsqHgTyYeIIxyaL9PwtyNyWV5KLXh4eQx1tJmBXzQMjbm/8AThLRbch+9MKiSf2R/Cv8VTyx2etSF2f9P+4t34Atzd5mp/mPjizYgE3ffLa0gkuJ5ViijBLMxoABhGzFW2+w3ju26F2yPabMprCWH5koH3lU/bkPPErWfgosF+ttq2zY9qa8uHj23bgaPdzmryvyCD4pGPKmJOKmbKH3R37um53J2rYbFuhIemoapubgHix0ZRp4r9JwXVc24+BZngr+vbNiupH3Epue+wLSHb4iPlrapIRZXGnquK5heGEc7OOA8HenvfcW6fMXbalIEQ0qUTSBpKRJ90HyywmzbWmK8hrWcsMXPeO09pQCw2RFv+4WUoJh64bQ0pVj9+T6hiNW3x/mM/hFJEG6Xksl1eytcXdwxkmlckszNSvnTLF6VVSlaQS12GdgNWVeFeP0Yp2HgkwdrK3q00AzLtg9hYJcXbu3q9NHWPMYPY0BiS0DsgICLGoUKvKnLGQWx1FijHpUDx8T78EUH3iSUe6aRV6akkCvAcvbjQPX4KN35tNzBuNupBBvY1ljUeLYvB3K+BHblilvvaW0jNJuN1FWWReCADIe3PAdsHFfksIjvDcfL26CUxSqJSeKjxYnEGBBjcZreO30ROszNJpmiHOnEDzwtORoKf3Vc21vGJbRmEE1QisM1ccVOLUlsauSttN1HjkrRmUasueGsj1NL/GB8NI9Ap1HwwC6LFsW3o1GuInVSfipl9OMUcFsftiOS31WdxRqfA2YxoJ92VHebLcLJylzEdH4qVGBBVWK9ehRGJY/S6kEHAbJ3rKLvtPd3dVxs0O32UsdukQ0teEa5aHgEB9K+3PHLttDPPvryNx7GrTm7u3e8u2+K5uGLv7tXD3Yg9jZlRIn/LRqQqes+QoMIMOx29DVjQeGMaR2qfD9ON1BJ9UA4+rPmxYOMYUDjGPVxjHq4xiBcik58GGOfaslaMH3AqCOGIMsis91s0WzXTltCqhq3AcPHEdnALWg+e53Zo3ncl3kqSx405Y8Wz7OSbLx+nnbkVjtzbvdIfmLjNBTgKkZY9DVSEXog/OUCxuGIoTQHhwGeGZVESUkIWBGkONXLMtywoSLPMrSFgOQGfKgwBlUahtHYZDQDxZvLLIYZIzJEdguljTW33QeHvwyQBT2kmgVIIZiCBlSgzzw0AGjZufgUUNAT418vDGMNyWg0kn1E5heWMAjyws1Ci0yoPtwJNA08LMp050rmeGX7cEAnosGJLksOK4IBLzTZUz4ZU/dgyaBn5qcgqwFCCCOPH6sEAzK8EoEcq0X6DwpywHSRYO2D7laXUdzYSM08eUZHwsgJJU0FaY5d/rd19RepoWx96Sb9cRbNHqgvirNeyj1LBAmcstffRfFiBiPq02Xt1suOWB2gIbtusJcLH+VbxKIreKuSRqPSKnn4n349l2JlJ7l7127aoSZHMkzemOGManZjwVVHM4RmO9o/p5v3c8yb33Mois4/wAy12tjSCFRn1Ll/wDUk8uAxJ2T+wyCHd/6ydm9po+37FGm/btH6ZJQwSyizp6nH9TT+FPecJM/xCYt3Nu/dPctym+dyX0zqx1WsRBQCBv+XAPRFH4Nx9uN1j7gILb3uQR1hupLe31UOliDIBwDkZk0ypXC21prIUiXtrwmaOa7SQugNIhUKwP468fZiV3d4rhD11sPbpvO7Twi3s5VsrSRQHlT+rTmpPIeQwi9ZLkstF7DNhLsFnUFiGJJdzmxJzOeHg6aeo1wGIe5O34mVI/vcXpngFP+LYOW0lvc0e1CzFubZAYKRz2q1yOyQmv5zVpyAoMOiZ1fSPyky8QMMgMbkjudQKxElsiMGGERJBd6aAqteH7sEEAfd+oLcwiQNIxUdMZmhPMYKOj1qTckdxbYl5BZ7nMkrypGYxAtKenIEHlilpfB2WrFIr/mVXawJdwjS3ToSJKCHU1aoOetjgRCycd9YQ3e8gtL+UPN0VUhpJAadRsTiULWpC/7tiguiduWOd5aH1/CH4avLDV1tjWQNu5Vn3KCzaRZ11NNM5FFEjZmnlnjp1V8gqRN9trRb2OGCQOwHr08K4Gw79Dkd2vaLqeUCPiORxM61g0Xt+ykiiEUxKP+Fs1OChbuSwfJQEfD0W/Gvw4LJpgDuKC4EDodNxERkRxGJs6KQZduqCISfhzwrGuoRY+yXrazKBWmkg+7HH7CycOzksLNGvxtn4DEIJtjZuo1B0qcN1FbEiaR+WXhgwCRXrp/4pjAPq0HH1B88KBxjCwcYx2uMY9XGMAN43VbfcYUfJc6+/Gersjd+rHpgjLrXNSKg44bKDqTKV+rk72PYjOreu+lSArzAbicQ9p9dTZOzlmF3MIKxoODMq09+PF1m8muq1vY7fa9RggEI0JxJqScgPbj1VhHVVFd3juCzsoRNcnRHX0qaVY0HLlibyG1lUpe5fqHHJctFYjSvEs3qpildXyS/cxq37svpEErzlQx9FQMx5VwXRG/cyNcfqFukM7IJtWjIVA4e7AgH7mEds/UbdmUGaBZUHMih92DAy2stW092bTuH5bVgn5Rvwz8DgMqrSFTI+YrpUcKcaEYEhEaRppSgOVT4+zBAIe3iUamJKkDUTQDkMaDDDgGojzFK6j4Y0mgb+WZtQUEtTkK8sFIB2TbnVq1HCuVD9eG6gkivaEEgA6eYJoc/HGARZLNiragNJHPIeRwJDBxYpbZdaElgfhBp9NeWMaC0i+fYtkS20KN23BVmvXAzjh+KCAnjkDrYeJA+7joShQc93LK88l/uDs8k3Rt1+KRswPGg+83lhXZINdckRN02bbb6OVLA3MUJ1NNcUq8gzXqEerQDnQY59lnZYKWpCwAu8e9+6u5J2tLq91bUQAthZsY4EI/lprrzD1xLslzlgWtsqMvb1z0gBGMuAIHsw1NjbKfpwEZE+Ysbe0uBqmhWjSEngDkPoyxVsNfX+RmPbbJtKumop/T8F9gwEjprqS4HLy9jiAUkVGQpgNnTr1yDZNxINF4Ym7Hfr0jRmkkFae/ErXOymk8olOYOJPYW/Ughtu6XVtL6ZGWnChywyuR2+rWy4LlsfeMcaFdxHUBOUo4+WL1ueR7PoNfxLfb31tc26vAQUOZI8cVTPMtR1cMhXm5wQoys9XByCnP340gSKnvHcdwzt0vykHMHPGSkaCHs2/3E8k0ICalC+ulXoT44bqdvpa1a2TUb7tmyuOzZ9xJlNyqBGUMQq+OQx1qkIPsb52dFwZxBaWiwJGTokFVjYZVH78c1qsRld328tJ4ZIb+2dJoqi0ZT4ZVbxxqqAdPIF2eNGYxtQO5yryIwZK9Uy1WPbfXBBOnStVfxOGVxHRES52r5Yx9KgaY0dyKnLwwLWydOqsF12DZ0gtlYeqUCtTzxkVbDltBqOp8m/CcMFkiS4ECFCaqcmBwGzKpV9/u1WrwNQUzGJtl6ozfepkkD6c2c0A8zhDbHgP9qARWUpJ01IX6Bjn28nn7XkNVLD0JQHizZDEiItLep9R1ezIY0mJaRKKcMAw56KUyrgBPp4HH1J86LBxjCxjGOg4xjuMYoPdySw7/AGzSSFo5VYKh5EZ4vpfglsQSt5Z0RTH+ZCRmvMVwm3SrfcfXsaKX+vV1LAdl24ELFOrvIhzzUih92PA/uc1okXWWZFfkRRRyqc1YMPca48rWwhO2/UHZZJEjlZjcBKSO54lR449WmttSdD3QsFM3/vC8u2uhpQpICqEipVfBa4pWqOZ2bKvZ3LfNQwReiSVguric+eeLJAD2+ymJfkmcPJbmiumZqBTTUYg3kyIG27ZcXU2p1KoOJPPBbgZItKaVt+kkY1LkGwsjIbQuGJ4MOFMYMll7Z7sm+Y+Tv5PRSkbkZ15YEFK7PkuYb0hhTMVDDPj7aYBYSsbyMwWrBT6q8APqGCYeFmvFjXiCeA8aA4bqK2O9MhSQukHicGQCJFBFGNacPZ7cCTQNG2MgUKAAMjXACdNglAWqx5Dxw0AkTZ21o16HlKLb2yiaVCR+YUNEjpxOt6Vpyrh6LItngG3Ml3fX8skkMrF2LSSMD6iTU5DMDAvsyausdXbru4CoseQFFrRVA8vDEcsoQdxsNotY2N/cpqH+jGan3k4DGrRsqF9ve02MxSxt0k8HOdMZUkstSBM+5zz+p8vIZDDqsDqomJiSTTM8MEaBq8uzAtVyanDCtlteuQPE7TXP5h+LErWO+urBJuLAI/p40riLsdWpDcakDy54lZndWhJTTTEmU/WdaIcRjKw3UaLSpwJFM8Vrc57a5CG3dwbhBIAuooPjVTkRi9bnDu9GtkWAbzZXdr1Vf8zg0f8Asxerk8Lf61tbyVreLl2BC+lRxp9pxWpzCOyi8m9EKjyoNLShRX0g54okdnqWhs+wuy4dl3rslIIAjRTq6ygfEGJ+8OOWO5LB53tN12yY93d2fZbXdx2lw4jIWSSNh5A0GIWqdurZKkxTcn1wRl5DI5dxU8hU0xGyg6IO7bDR9fFgNS+0Yi7jKpc7SSSXbY5kyJypXg3ngTArQhoHntokmNZY2NQMF8ltTLZs80CWyR1NVHxHFExoySrncLdNNW0uOBGDI9age77hjIkSSmrkMI2WVSlbtvBaQqDkcLyNwVeWaSS9FBRF5+JwrIbLF92W0FvYRKR+Yw1t7TjkvbJw3csIqo4n6cIKLEijh6jjGHKMfi9I8BgGFUWlKZczjAk+nVx9SfPCxjGHFxjChjGFAYxip992Rb5K8p6YZQHPgrZHFNdoYmxGcdz/AKkWOxXkW3bfMLjcJpUiQA+hdTAeo+VcLs9qswgV1sf/APkEXG5bD1aNIYHq48Qc/prjwP7pPWp01Mlv3DWuXHHl0MZturvHeyZ0Iaox7ml/igjTXLyAauNMMCCb27YXF9u8bR+mOE6nfkMF2hGLFeXtlBJIluokcklpTzPPEJCQzut2p9LUHhjSB2FLv92p4VxpNJ07lNKwcHSfDGGTCG03kRuVaXOhzBwGY1Tta9gvUkhA1mIApnSgJ8sLU6KWwHhHmoNB+EcgAfDFBjjyoCVAzzC88/LGk0CCZCKnIeJNTgGOnppQ/F4g5f4YMGFL1pBqAotTRjkPP24MAOt0VC1YuT8fJT5eODKMJ9ANYowCMg+mn0HAk0EXcd527bY9V/Oo4kRjiTTwHHAHprtbgpXcH6lXJjEO3oIlapqfip4nAiTorpS5M/u9yvby6eaWUtq+I4ZVRT6C7WCWRS+khfE4zZggm3OVDMcuWF7GQ9JCsaUrnhXYtr1tgy9QNXMHzxG9j0tGogJF6qjiMc7sejXWiYJJX9Nat4DjhJZWupBfY+1ri8cSzjRGOCnHRTSJs3qmEWk9o23R0qBq5HFHqI19pyVzeNhksDqA9J5Y5NuuDt1bVcBzIK1PDE6Md1GKMrHpVqeWKp/AnQZbqwsGQkNWpxSt4IbtKssjr3XzK6JRRhwA4HHVr2SeB7XoOuakPb7252/c1eKQw6vQaZE1x0eDi9fb0ua32H+p1x2zb3IdtMrrpj5gknmDiura0oPX9n0abkmVzvr9Qbnft3+YMp9I0hBwGVMM7Scf6P1qDPpbr0FQcwxOEsgIciv3VVYNQqc6Yg6DSWDb+5DFbyW0i64ZPVTzGE6hiSQncsckqyhjG6ZCPkTjQ0PWsBb+/EaJ42AVx+YngcOmVSGrnejKM2z+6cEpVoCbjupb0GpkHDTxwo3aATNcMaq/xfswWRdyRs1oLq+jV/gU6nPkMSvaEc+2xfo2VgAq0AyBOOM5hYCV9RLnwGMYeUheQQYBjxap9I1eZwQHqPWurPkMYx9QLj6g+eHFxjC1xjDgGMYav76y26zkvb6ZYLWEapJXNABgNwY+a/1d/XGfeJH2rYy1vtkRIeU5PMfHyXHFt39sIZIxO63CSWdZ3clldW1E55MDiepQ0Oz6N/8AkLd27Wnat3HKJOtC9HHArpU199cQ/uKTovuCpkE10HgoM8eVWoWVfcdpmupi0YAbzx6ei0KAjQ7Y3Fo1EYDStkErTFk8mLHZ7VNtWxSJKRFdP/UWudD54S+WCAHQlq4UzFKhc0GZwoDzQdNqHjzw6MdZClD9GDAB+AEjWpzwB0XXsDcGh3QRkk9ZdNAc8ArreTTn1ilWoRllmaeeGLHC+SrGp1czxY+XhjGPMrkjqMFHgM2/djGOr00NaUAzLtmcGQCzIXPp+GvE5D3Y3JjzIv3zWpNPDPwGDBip9097RWKPa7fSW5Ao8xzWP2DxwjZ2afWnNuCgG9N1K09zOZZ2zLNgQdFr4hIZWG2MhZiZK4JJyyZb29okWkRrU8zgG6nZru0gFHIovIYDKV1tg+67j1emJaKOGJWtB26vVIjXc83GoxC2w9DX66Qkwuc2JOJPYddaJHPShpXA5HVWWzs6222eFjKF6y8a46daUCexay44LPDe2ETBOoqgYvW6OK+qzyTju23pFUSBjjWuha6bNlY7k3eK4j6aAHzxxb9mD0fX1OpUp1y1UyGWOeiOh5C/aO1QXs0s03wrkox2aKYOb2LuiSQje+336rtDxHwinHDX1g17U1krc1u6NpZSko5HEU3Vj21qPoRN1MRs+qEK3MfEqK6qY79O5PB4Hv8AoNfnURZ7tJuMCyqDriI1BuNVx0R1ZT0t/en1IF/NMk0r1oXNa4omLuIC3ZauvieYxmcPclRSDp5GoOJMZMlwyenjmvDCsdMe6lT1F5ccZlFYmWt1ojYtIGU8UrngNDLYdF3KzaVNF5VwAqw08qjJRRz97GG7QNpG8j0pViaAYFnAjZctjsI7S3rTVM+bn7Mcd7Sc1nLC6sB8Rz8BhADisx4DSPrxgCwF/mOMAWzED1kIo54wCGd0sxKIgxNTm/IYPVgPqxcfTnz46uMYcXGMPJp58eXhjGMO/Xn/AL/+QPzHT/sesdP5avS8upX1avbl4Y4PY/Z5/iUwfM178xX1+7EKwEhvXptXwOKGN2/UXX/2V2j/AHPqV6R6fCnwLXhnwpji2/8At8mqZ1c6+n/01NH141OoQWfm9R418sVMKHz9RTXXl44IMip/7hT8/X56q1wHJskcccTyAnWHQ6orx54pUDHt3+W6o0eGeHGqDm/p5+6uMB8i4NWdPfgMKDvafU/vdvprXVy8MArTk2VdGoa61zrT4eGXDPDIsIvOp8g+ivToaaK15atGn73twl5gasCYfhGj+rT8vXWvLx541eDMWNFc69Sh4/ZywyAOvqqmmnwjVWlfrywWZAvuD+6f2yb+2061PXWuvT5YUpricmTX3U6Z6nwV9dONedcFHbafI1b/ACukePLDCEiHTQ0015VwrGQzc/O0OilMKVrADuvmdZ6tcTtJ36up6DpV9Vcc15O2hPh6WWOe0nRUeamVfgr6qcaYFYnJakBd/wDtz+2HT/Up5Vrjs/GCf59gRYfNa3+T1U+9TEc+DpceR6TXU9XXr9+I/lIXPgXD16ejXTzr9uN+QyjyOHX9/wB2JXnya3GCJc6tI8PtxSoC39sdP5FPl/D1eNcehr4wcHs/yySrvrVNNOr68OyVYKv3J8tqT/8Ak+WOfbB2af8AQCS9DQ3U+GhriNJk146uSu7dX56X5SvTz6nhj1azGT5an/7P9fA5f6qjq8MOpOnbIK/LqdPDBZwD8PKnDCsNTknzGs6OGChhVr8xrPx6fvU4YLBXknW3T0tp/qefHCM6KQPr1c6+7CFB3kOpx+vAM+AttPyvVGr4uWI7JIXks0eqgp8P8OOdiEmPh6ePngGHPXUavqwQDv52j8jTq88ZAA9987qPXr9mHQCGNNDWteWGMf/Z\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'policy-and-advice\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_1\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'4\',
      \'current_revision_id\' => \'198\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Policy & advice\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'5\',
        \'source\' => \'node/3\',
        \'alias\' => \'policy-advice\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'200\',
      \'uid\' => \'1\',
      \'title\' => \'Enforcement and regulation\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5f09b377-b7d5-4012-9e5c-9b32940d6872\',
      \'nid\' => \'5\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442205\',
      \'changed\' => \'1395490422\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'35faa675-ba52-4be4-9a85-66356897d121\',
      \'revision_timestamp\' => \'1395490422\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>As well as information on food safety legislation, this section also provides enforcement officers with all the tools they need to ensure that food safety and legal requirements are maintained and monitored in their area.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>As well as information on food safety legislation, this section also provides enforcement officers with all the tools they need to ensure that food safety and legal requirements are maintained and monitored in their area.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency works closely with local authority enforcement officers to make sure food law is applied throughout the food chain.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency works closely with local authority enforcement officers to make sure food law is applied throughout the food chain.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'enforcement.jpg\',
            \'uri\' => \'public://banner-image/enforcement.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'13866\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'8cf22425-4c26-4595-b322-7796e76716b8\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'/9j/4AAQSkZJRgABAgAAZABkAAD/7AARRHVja3kAAQAEAAAAPAAA/+4ADkFkb2JlAGTAAAAAAf/bAIQABgQEBAUEBgUFBgkGBQYJCwgGBggLDAoKCwoKDBAMDAwMDAwQDA4PEA8ODBMTFBQTExwbGxscHx8fHx8fHx8fHwEHBwcNDA0YEBAYGhURFRofHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8f/8AAEQgApAHOAwERAAIRAQMRAf/EALQAAAICAwEBAQAAAAAAAAAAAAABAgYDBQcECAkBAQEAAwEBAQAAAAAAAAAAAAABAgMEBQYHEAABAwMCBAMEBQcJBgILAAABAgMEABEFIQYxQRIHUWETcSIyFIGRoUJSscFiIxUWCPDR4XKSojNDJPGCslM0F4NV0vJjc5NEJTUmNjcRAQACAQEFBgQGAgMBAAAAAAABAhEDITESBAVBUWHRMhNxgbEi8JGhQjMGweFiIxSC/9oADAMBAAIRAxEAPwD6kqoKBXoCgKAoCgVAE0CoACgi840w0XX1oZaTqpxxQSke0m1JlYiZnEKtl+6ewMUVJfy7T7qf8qIDIPsu2FJ+s1qtr1jtd+j0rmNTdSY+Oz6tHG777QkOyWm4eQUtlkvsJDSCXkIUlLnTZenp9aSq/I3pTWi25jznIX5eYi8xme5oc134yaGyYeNi41o8JORfCj7Q2no/KaymziUfId2MxlHm0z8pMyEIqT60WA18vGWi9yhTgCUkEeKqmRWIGJ7kZuS8MLio+MilZCFMMryMgAqNgXFj0vpq4Ra8f/DbvHNWVubKPFlZutiXJJQNPux4xCB/aFXhV0fBdgdr4jGuwmZCgZCm/WdbaQ1ZtIUHGmwOAdCyFEm9qYFmi9stnsuB2RHcnv6lTst1ThUopCVKIFhdXTc+dUWOFi4EMWgwmYwJJPpNpRck3OoA50HpWClJW6sIQOKlHQfXQaDKb62Zir/N5NpSxoW2j6ir+FkXqZFQynffENdScVjXJKhoHXiG0+37xqcQpuX70bymBQZeagNngGU3V/aVepkUyfmctlFlUyU/MUTc9alEfltWOR5Qm2hWlvyHvH7NPtpkALQJskrPio2H1D+eqMiXTawAA8E6UGRIuLkaeJqozoSpRSEC6lcABc/VRG3hbZzExSemOUIPFbnujTyOtZYFrxXbpk9JlvKf4XbbHQn6VcTTAvOI2vEioCI7CGUDwGp+niaosEfGNIA04UV7m46R8Kb2oPDK3HgYgnhycyt/FtF+bEaWlyQ2kI69WkkruU8BbWitN+/zs2Bi8jt3CycxCnOKRKUr/SOR0pA1KHgnqNzyNvOoMj8LeU+RmIk3IsRcNKQUY5cJKkzGbgDVwnpvxN7VcDBE7fYFMWG1PDuUkQnFPNy5a1KcK1FPxWIBHuDQ0isIsqY7aXFuJQlLjhu4tKQCo+ZHGshlCBfzoJAUDtUDoHQFA6AoCgKCLzLL7LjEhtLzDqSh1pwBSFJOhCknQg0WJmJzD597odoH8AXc1t9tT+D1VIii63IoPEjiVNefFPPTWuTW5ftr+Xk+w6X1mNTGnqz9/ZPf8fFzFJBAN9DbUa2HjXE+hMk6+PjRYIEAnn4ig2eB3DlsBkm8jipCo8lGhtqhafwOJ4KFZRMxOYaOY5amtTgvGYd1id7cVK2dOyyGEozkBtBdxi1WStTjiWg42ripAK7kcRw867I5nNZ73yN+hXrr1pM/9dv3fr+bpldTwSoCgKAoCgLE0Hnm5DHwG/UnS2Yjf433ENj61EVJtEb2dNO15xWJn4Klk+8Xb2B1AZIzXE8W4ja3f79gj+9Wq3MUh6Ol0bmb/t4fjs/2p+V/iIQApOIwpJ+49LdAH/w2wf8AirVbmu6Hp6X9cn99/wAoUvL95e4GR6kpyCYLSv8ALhtpbP8AbV1r/vVonXtPa9TS6Ly1P28XxlU8hlMnkF9eQmvzF8byHVu/8RNa5mZ3vR09KlNlaxX4QwRmX3+oR2ysNjqcIHupHipR91P0mkRM7l1NStIzeYrHjLz5LfmGwWDnQXJkKVNdCnoKWXFvvNPFstOID0U9KEPN+4tJcFrJVxTXTpado2dj5fq/M8rrYmLTN690bJ+ctp2qy3ZPduYjw8u5KwOTe6UNwZbiHo77xNkhqctPWkq5JWkG+gUTXVEYfOTD6axfb3ZuKQlEfFMqWng5IHzC/rc6vsrJFiQyUoCG0dKBwSAEpH0CwoJ+ioC6lBIHE0Goym7dp4oH5/JsoWni2FhSv7KLmpkVDJ98tvMXTjIL81XALUAyj61XNTiFQy/evdkkKEX5fHtnQdI9Rf1q0+ypkUjK7qzGRWTkMlIk9R1Spw9P9kaVMjWl49PU22ADzNh+XWggp1RPvKNvBIt9pqB9SR8KAPM+8ft0qiJUo/EokeB4fVTCZMAdPCmBlajvOH3EFXsFXA2kDb819VzZtI1Kla6VcIsuM2bFv1O9TyjYW1CfqqjZS8jtLbrQ+bWhEhPCOyn1Hzpw04e1RosQz7dzu5t0Oq/d7CpjQgQF5LIKKgOWjaLX9l6ZXDoLCImMhvrnTm3nITRenSFdDaWm0pKiotp+FNhzojWvdz9tpxONymIZl7gh5F/0AvFsqeLIAupbyT0lIGmnE0z3K9wyW+pOYyUNvHRcfhlxyMTl1O+pJQ8pvRbsa3SbLOibi1tauJR4xsnK5TEY2LujPS5uQxj5kNzoBOPKzbpT6iWj7xApwrlvou28HGyb2UjwGG8nIFn5wQPWWLAHqc+I3A11qo2QbqiYQKBhIoHaoGKB0BQOgKAoHQFAUBQFAfaDoQeBoOKdz+y6kKezu02T0G65uHbHDmpyMn8rf9nwrn1tDi2xv+r6fpfWsY09adnZbz83F7pNyAfDpPEW41wTD6uJLhry5UVKxItz+ygYKrHTWoj7Sr2H5aKBgE8BQa7KbhwOKSpWTyMaH06lLrqEq+hN+o/QKxteI3y3aXL6mp6Kzb4QpuW76bEhBSYjj+TdHAMNlCL+a3ej7Aa025msbtr1dHoHMX9URX4z5ZUvLfxD5pzqTisTHiJOgckLU+sHxsn00/lrTbm57Iepo/1vTj13mfhs81PyndDfmUJS/mnmkKv+rjWjptzH6sJUfpNaZ1rT2vS0ulctp7qRPx2/VWn3VvrLsha3nFaqcdUVqP0quawl3ViK7I2fBAmwFuHgKKiFm1tPKgS1XOpPs53ogIUdARrpfkNeJomVK72Zp1e5VbfhBbG3cPZmEgjo+acSLOznR95byiSkn4UdKRpXpacRjY/O+b5m+tqTe+/u7vCHOK2OYw2s/dNMj7A7C/xDOy9lSsXuJLmQz2AbSW3gep2RCKg2lxxR4qaWpKFq4kFJNz1Gscq32U74bmfChBjx4DZ4KXd1YH02FTKKXl98Z3JEiflZD4P+UhRbR/ZRaiNJ82eLTOv4iPzmgxLkPqv1LCfIamoMRstQuSfyfZTCsiUISToAeR41cIlragYbvy+k0GRuE8s+6nTx4VUelrFk/wCIrTwTQe+NimiR0t3PidaCwY/EshIU4b/o/wArUHoyGf29hWUqkOi50Q0kdSj0jwHC3O9UiFUzncWXLQY2PDscPKU0y22gpcWtKQenqI5gjha9YZlnFY7Wz2v2/wByu5aaJW31LdYjKXCk5I9EVcpSB0KcSCVrQlR+HibVlFZWbQ6TH2lv6fiMO1OzqNvysY4VusYJsIYfB0AcC9CLfdtb21eHvY5biD242rGzsvOmKqRlZ6ema/IcU6lz3Qk9Taj6fAfh05VliEWKHAiw2QxEZbjspJKW2khCQTzskAVR6A2KCXQKCVqAtUDtQFqB0BQFA6AoCgKB0BQFAUBQFAwbG440HMe5vZyLuAvZnAhEXOkFb0c2SzKPnyQ4fxcD97xrVq6MX+L3OmdYtoYpfbp/rHw8nz7JjSoct2JMYXHmMKKJEd0FK0qHIg159qzWcS+y071vWLVnNZQ15HhWLYLm3D3vHzqDveT/AIidtsrKMbjJU0Dg66Ux0HzF+tf1prunmo7IfH6X9c1Zj77Vr+v4/NVMj/EDvGSVIgxYePR91XSp5wD2rIT/AHa025q07npaX9d0K+qbW/RUspv3euUCxNzUtba79TKFlps+IKGugVqtqWntelpdP5fT9NK/X6tAognqUbrVr1HU/STWt2xA4DkPCqIknXqOlqgZUb8fpqoLHxIHhVTAI8L/AF0SIJdzbT+e9EwiE3IBHnf+mhl6YEaXKlNRYbDkqS4bIYYbLi1eNkJBNZRWZ3NWpq1pGbTwx4tRnO3CTLck5XHvMqStaOidIENorSelXSlw+qoacb16ERh+b2nbPxajffaXee38YxlZmDbxmFdCS3LiqQ+D1jqT6jgWtSbjhcCk5Ic5lxWm1+mlRW7exb4m/sFWJkbvt65m8duiFkocN92KhZanBCSEqiuj030FR93VtRtfnrVkh2GY2lt5xBur01qRck2PSbX+m16iMHqkfCkJ9lRC9RSuJJNUTS0tXI0HpREUq2h86qMyYKzysaDOmCbjw50HqQwhPBNvOoMoGun01RJElgP/AC6VoU8AF+mogq6SbA9I1sTUyuGfGnPZaDJkYDFSJj8dQSthxJjfe6eLluWoterESYWuF213zLehyHZrGNhrbKZsFxJdeTc8QtB6OoDhrarFRvsP2P2fCclKmetl2pPVZiapK0NhfxdISEnUD2VlEQuVzxW28LiobMLHwmY0Zi5ZbQke6TxIJ1vVRsg3QTCBQSCRUDtQFqBgUEX3WY7Kn5LiGGEC63XVBCEjxKlWFBocZ3A2Zls1+xcTk0ZKcAorMNDr8dHSOohcptKmEKtwCl3oLDQFAUBQFA6AoCgKAoCgdAUBQFAUBQU/uH20xG8YfWbRM0ym0XIJHHwbeA+NH2jl54alItGJej0/qV+Wts20nfH47Xzfk9rbixeaVhJkFwZMH3WkAqDieS0K+FSD+LlztXn20rROH22nz2jbS93iiKePZ4LU32uko2+7LkTWV5h1IMKIh5KWEdKx1+o+bpWopukWskKPxGs/Ynd+541v7DT3YiIn2u2e2fhHdn5q5uPDSsVk3mZDfpuocU26j8LieIHkeKa55iYnEvodLUrq0i9fTZqgAeN7kaWozHHnp/LjRR1WOnEVAib+3mLVVInQgi/hRMoqVr7aCSeAJPKqxk1eZPsphETp7Ry8qJmSBJOoBA538qJOx0bs1vHbmAm5SPlJbOLl5JttEDKyR+pQpsqKmnF3SEBRUFaqANuN7V08vqRGYl4HXOV1NStbVjirXfH+Xh7vbHz+4c3JzeB2/l5i8g0GH8his1CEKQxeyQgLQ48EqIuUaJrpxne+XvWK7p29uzGFTwHbTezWA9DcaThu36HfVkwW8iiVJmyEApTH6mlrbb6iT1kIRZIPE2rKMQ1SjmN4bVxLbkbGR4mOSr4oeOZTfTgFKSFLV/vKoilzt17gn3TBx60t8At89Cbf1RThFs22nJTMU2qb0qlpSPW6L2uCUDj+igH6aTCS3DeIe+90N+KXFAH6qxyYehvFNj45CNOSATUyuGziYzEFY9SQ4q/4EAa+0mrEphYYu3NuudKUSVuOKA6WyoA/UBVMFOwe3orDz7kwMtRyEurUoKspXAWApkw1cjHITMaZhh+YxJH6iRHZU6jqI0Sspvam0w2+N7b7tlyXmZbCIDAF2phcS7e6fhLSdb9XnasuGRvsf2ViuwWm83kXn5Ta0rS9CJjfCDbq1VdRvraw8qvDAuEDYm1YUhiUxjGPnIyQlqWpAU8Lc+si9/OrA36WQBYCwHAVRkDdqCQQKCQAoHaoCgYSTwH1UGMSI5kmKHmzKSj1FR+pPqBFwOoov1WueNBUO4/caXsvHPzm9sZHNR4zQfflRiyiK2kqKbLWpZdunirpaNhrVwK7undHcncG1dtZzYTcd3ET0+tuJWPlRxLbR7t24z85LbKSPeClKR1JI4VI2wKZkNzx8ROxsPeGzZG41TJiEQ4eQzUTOzmnFAguNwW0LSkEfFZXTe3OmReHO2W5dob6az3bhcZvBZV0Dcu15TimYouP+oilKV+mofhCdD+joE7do6kQL6cOVAqAoCgKB0BQFAhegdAXoCgKAvQOgKBXA1JsBqT4CgqO6u5m3sDIMEvJcn9IWUkKLbYIuOojiTyA+usq14ozG5cd7iO7N+ZTccxwCQsoIKEtoGnRe/TpbTyFb61xCTMKy1l882HoinldT6EtIQQD+rSq/SE8k8a1TSszErmzuXd7Zrc+Cc2yizsdITkEpGqmhoh0ebd9f0fZXBzOlmOKH0fQOf4Lezb029Phb/f1cHksOMuraXopGluRv51wvsJ2MJTx8BVTJdIA5/y8L0JSFtL/AEUEVdP0edA+knQ6f0UwxyXSRYnRPI1SUmG3H3Q1HbW+8rRLLSS4q50t0puaREzuYWmKxmZxHit+I7Rdwsr09OLMFhX+fOWGAP8Aw/ed/uVvjl7S8zW6zy2n+7in/j57l3w38ObQsrO5ta+HVHgICBp/7V3q/wCAVurysdsvJ1v7Faf464+O1dsP2n7e4lADWHaluji/P/1Sz9Dl0D6E1urpVjdDytfqnMam+0xHhs+ja5Ham2cg2lqZiorraE+mhJaQLJ/CLAWFbHBlXcr2l2PJxisbHxiIURS/VU1FKmkFdunqKAekm3O1VFIe7C4aMSYqra6XQL/ZVR5f+zzfplxDgNiUkFJGo1oMUrYjuJjNSWQHVtqJeQnQdCkhRsLKuQpCbVrusPAzg3XmVOISXFJHW6QL2vx6jyrDCvQ3tDLuuR22GFEy+kt9Xu2Qq59RYJulPSL3pgbWB25zbzjqlEBluwZ4oLqyeIKgbISBx51lFJFhgdqClxpyVPUsD3nQhPSq4NwG13ukAaE86vAmVgxnbrbUH1emIHg6TdLxLqUgm9kJWSE/RWURAsUXHxYrKGY7SGWUCyG20hKUjyAqj0paHhQTDYoJBIoHaoHagLUAqyEFxZCEJF1LUQAAOZJoK9ufuDtHbW2HNzZHIIcxCF+k27EIkF165HpNdBIK7pPPS2tqDxYjdW8c6yVxNqyMPHlxlu4zJ5N6M4gOFHUz8xEYe9ZKFeRuOYoOLbn7l91M7Pxmw5uOmY7dOOmrkbjZwjgYVNxrQCh8oVuJUrraKvdCvesD4gJFj3SziN6Z1rdPb4TcD3UwyOowchCkwzKZbTrGlFaPRKikdKFddj8J0sU3wkX7EZXu7l0QzP27isBDUGxlWp0pcx9xKgPWDLMcemgcen1HD5ioPFsnslhNrPyHUZfIy2ZT70iRiQ4mPi1l4FJQqE0AhSAg9PSokWtppSd+Rc8LtjbOCChhMRCxfWLLMOO0wVD9ItpTf6aDZUBQFAUBQFAUDoFQFAUDoFQO9AqB3oDXlxoKzundOIZlxtstzWznMm4ltuElXvhFislZF+gEJ58a0c3n25x24j85w26Pq+G1867kyL0zOZF9+MhmU9JV6qT8LZSOnp18OmtvJWzpx/x2MdWMS88OSiLHK02Lir/rDXRaWNYVKRLfRuWK565VJdUo3B91KUoJ1H2VOJnwvt2Q2laFJUkLQoFK0q1BBFiCK1MYfPPcfZZxGSU0ylRiuAuY9ziS395q/wCJs8PKvL1tPgnwffdK5/8A9Ont9ddlv8T8/qoPAWA1HEcK1vTRJ1vfUUCuSOfVyP5aIkek+R50Mrx257XtbzZkSTmW4iIjgbkRW2y5ITfVCj1FKQFWNjrwPhXTpaEWjOXjdS6tPLW4YpmZ7ex1fD9jdgQCFyY72VdFj1THSUXHP02/TR9YNdNeXpHY+e1uuczfdPDHh5713x+NxuNY9DGxGITI/wAuO2ltP1JArdEYeVfUtec2mZnxZzc+dGAtQLpoF00CLYPKgxKjJPGgwrx7SuIqjyubdiOkdSlo1v7hAP5KZMMLW08e3FMU3WyXFOqFgglajxJTYnTSpge1OMZCirpBKuJOp+2qM6YyU8BYUEw0KCQbFQPpqh2qAtQOg1uf3Jt/buOORz2Rj4yCCEh+SsIClHglAOqleSdaCuTu6uFXgcnk9uQ5m4JOMaEh3HNR34jq2SbFxoym2/USnn6fUfKqKfnu9Uzcu0Isztat6VuUlp6ViP2c9MKEKPvsvvgBhgjWyir3hw4g1BTN1zH+4uMY7hbcQrKZbb6ejcvbvJlyVGacbSUlxEMrQFAEXsPit+MKSX1RaMFjTuzaqNu5Db+cyuFyvoOLcehY/AwsXa5LkFr9W6pSCs8lhVuNiblW/G9t9947EpwcfuHLGHaR6LCjBjKyDbNukITLUSNBoFFvqHI8KDfxO321GW8IZUP9qztvNhvF5TIn5mYixCgovKFyQRp4crUFkK1HnQKgwGYyJyIQuX1NKfNh7qUJUEe8f0lHT2GsuGcZGesQUBQFAUBQFAUBQFAUBQFAUBQFBhmTIcGI9NmvojQ46St6Q6oJQhI5kmrED5h70fxP5RcheA2Mswoi2/1+bIIkruVIswD/AISb294jq/q1liITLlW1twz4Gew+6ZL5SiDIZlKWpRUop0StSidVHpUSa08xpzqaU17Zj9WWlfhvEzudD785GHA3S3kMasLhbjjJnxXAQWzcD1bEfeC7q9hrk5HXzaZ7J3+Fm7WpiIz2fRT4ufiyozjUdyzqGwElRtdXO1+OtelnvaXmMxq4WPjtY8Ovqtwt7anCz433aRcVgwV/du3I+cxLsFyyHQfUiP8ANt4D3VezkfKteppxeMOvkubty+pF6/OO+O583bhxMiFKeS836Dzay1Ja/C4PzK4g15k1xOJfoenq11Kxas5rbc0ul+N7c6jYLJNxz5UCuQCOXDSiS3G0d1ZDam4Y+ahArSj9XNig2D8ckdaP62l0HkryrbpanDOXFz3J15jTmk7+ye6fxvfVuIy2PzOKi5XHOh6DMbDrLg8DxBHJSToocjXpxOX59q6VtO01tGJh66NZ2oCgLUBagLUCtRR0igLCgOkUC6aA6aIOnwootRCtQO1AWFArUHPO7fa6fvF3BZrCT2oG5dsyDJxhmJLsN26kLKHkC5T7zabKAPhbXQM8iR3yycBMNqJhNuTCUh/L/NPZCwBHUWIpYZF1D/mOUHv2/wBsNvbe3dP3NiH5UN7KItPxTDgRjnHTqp75fpUQsqNx72lz4mgsMTC4WHPlZGHj40bITTebMZZQh54i3+I4kBSuHM0HtJJ4mgVAUHjy+Zw2FiGZmZ8bGxBxfluoZRfw6llIvQVsdzMfO6RtnEZTcpXomRDjFiHfzlzDGZUPNtSqDDsTdpz+49wszoa8PnsciLFl4V9xDjraEeo4l5tSNHGXfWBSsca2WtHDEfFV1rWh0BQK9A6AoCgKBUBegL0BQFAUBQVjffcja+yYXr5d/qluJKo2OaIL7vK9vuIv95WntOlZRXJMvlre/cvePcaeG1KMbFIVePBauGUW+8ebi/0j9Fqy3MJlQt8YfHYuLEdQ4HJiepEhI1I6rLbUf6q06+RqTuSs7VIeyUpxpLHWUsNlXptX0SFEnp+2sMs+F0PaGTa3btVGzZ7wayuJUqVtuW4bjpN1OxleKedvC/4RXmcxX2r+5Hpt6vN2af314Z3xuafLRHcHIQ3NaLLshPqNdZCgkA9Khccekj6RY16HL8xGpXZ2NOpp8M4lqC+gvhYeWoA3U+VaJ9groYP0srUxY3EdQPjRXNO620BMiqzMZrqdjo6Mg2karYGvX5qa/wCH2VyczpZ+6Ox9D0LqHt29q0/bfd4W8pcJlxVR31N/Ek6tr/Ek8LVxQ+wmWApF7i1vL6qBE8Lak8TyNCD4nX66DonZruEnbuXGEyDnTg8o4A24o+7GlLOivJDnwr8DY+NdfL6uPtl8/wBb6d7tfdp6q7/GP9fR9GWsbV2vjRQOgKAoCgKBUBQFAUBQFAUUWoCwoFaiCgKBEUCoCgKAoEpKVJUlV+lQKT0kpNiLaKSQQfMUHJ9tbfwexN3pxW4ILM05h5R2vvWcn5iS48tRV+zpsh4qUiQm/wCpUkhLqRbRabFkdMM7LNC8uB6oHxKhuhzTx9NwNK+hN/prPhrO6fzVS8psSVlcMzuVmR+wt8R3XsjCyrwslkPH/o5afvx/RShtaTwt1DWste0TOI3RsGz7bdxcdvbEyHmghnLYt4xMzEaWl5lEhNwVMPoJQ60u10KSeHHWtSLbQFAUBQFAUBegKAoDSgKBUBoAVEgJAupR0AA5k1RxHuh/Edj8UXcRs0oyGT1Q5lLBxhs8P1CeDqh+I+5/WrKK43sZs4OqBksvIdzO45S1qeV6jrjyypa1eZPH2VWMy1Oe39BxzaoOHQOoaFY4/SRw9gqTOCK5c7n5GXOfL0lwrUeA5D2CsJnLZEYeaorLGkyIshqTHcU0+yoLacSbKSpJuCKlqxMYlYnE5h1hnK43uBt8RJRbj5eKQ44iwBvaxcYV+FX3k8j5a15M6duXtmvp/G92ccasYner42NlkKVi1KHpum6JgSop6QoKJUPuqsPh4X+9au2OepwTbt7mj2Zzh+hprraAaK8z7YIOgseIIuPqoOCdytlqxeQ/0yP9BLUpyAr8C+LjBPLxT5eyvN19LhnZul910jqHv6fDb+Sm/wAY7J83OXG+jS2tzca8eFaXrROWNIOpGtuRospJBta9r628DxoiCkJWClQ0IsQfOivoLsl3EXmcf+7mVdvmMcj/AErqz70mKnQG/NxrQL8RY+NejoavFGJ3vietdO9m/HSPst+k93k6jW94Z0BRRQFQFAUBVBUBQFqoKBUQUBQFAUUrUBRCoEaAoCgKDX5/A4fcGGlYXMxky8bNR0Psq04G6VJUNUrQoBSVDUEXGtBV8ftbua1ARipO8224URRbjZJmCh3KvxwT0fMPSFOR/VSmyVKSweq3UdTQelHarZ7zzcnNok7mmNm6X85IXMQDe90xldMVGv4GhQWxlplhlDDDaGWGx0ttNpCEJA5JSmwFBKgKAoFQF6AvQF6AvQFUFQAvoAL+yqNDunfm0NrRnH83lGY620kiIlQckrIHBDKbrJPst41YiZJl80dw+8u7e4L7mJwza8ZtxR6fl0n9Y+AdFPrT8Xj6afdHPqrLduYTKmPuYDbEcuylpkTbfCTex8D4nyFGKgbi3pk8u6R1lpjglA008NOFYzbuZxVXawZigKC97G7Jdyt6t/MYTEL+QsSMhKIjx1WsLIW5brOv3b0H152b7D7c2BiUuT2IuT3M+kiXkOgrQhKgAWmQ5f3fFXSCakR3mVzRsHY6HFuJwcTqcIK/1d06EK+E6DUVh7FM5xDLjt3rCRW1gRoIqAI1orR7lwEbM4t/HSPdDtiy6NVNup+Bwew/ZWF6RaMS6OV5m2jqRqV3x+sdz5w3HhZECdIZlM9ElhYblo8h99PLpWLEHwrzJjhnEv0LS1q6tI1KT9s/jHyaFxHTe2oOoJ8ONzascNtbZYhpoBYfnoyK5t03GlMmHpx2Qm43IRslAeLE+E4HY7o1stPJQ5pUPdUOYNZUtNZzDVraNdWk0t6ZfVuxd5QN3beZysWzb4/VT4t7lmQkDrR7OaTzFq9Ol4tGYfnvO8pbl9SaW+XjCwVm5BRRRDtRRQFAWoC1AWoC1ArUBQFQFAWqhUQUCNFI6UCogNAqAoCgKAoFQF6oYSo8BcVBqcJIdlTM1IWpZaTOMWMkk9IRGZQhXSOV3Su9bdSMRWPD6q2takFAr0DoFQOgOPtoOH9+u8sSBjZ20dry3HtxqH+vkRSAiO2j3nGfVBv6qgnpIT8Ivcg1nWO9LS+U8JuRudmAM2+UQ3PiIufe8zxNTiSYb3cHcKFBZVBwSB4KdH5yPyCmcJFZlzyXNlS3i9JcLjh5nl7ByrGZyziMMFRRQXnt52Y3/v15JwuPUjH3s7lZN2oiLcf1hHvkfhQCamR9T9tv4XNg7U9Kdmh+8mZRZQXIR0xG1ix/VsXIXY83L+wVcDswUAhKEgJQkBKEJFkgDQAAVkhXoDq1oM9qgRFArUGNxAINFc97n7TOQhjKxWuubDQUyGwNXow1I81I4jy0rm5jS4ozG+HudF6h7N/btP8A13/Se/zcByDCo7xDZuy4Oto8rHWuCJfZzTbteSyrfmoqKj9HLxosEbDl5/VQWft3vuTs3cKZx6l4uT0tZaMjUraBPS6kc1tFRI8Rcc63aOrwTt3PN6pyEczp4j119Pl831XFlRZkVmZEdS/FkoS6w8g3StCx1JUD4EGvSfA2rMTid8MtRDqgoCgKAoHQKgdAqAoCgVAUCoC1AUCoFRCoFxoCgVAXoC9BW96b8xe0hjEzYcybIzEkQsazDbQQ5JXYIaU88tlltS7+71rF9bcKDwF7u/mLhiJi9oxFAguylry88DkQyz8vGQf/ABXBRXkyXaqZkIa35W8s27uNrpex+XU+lmPGkNHqStMCOlmKtBt0rS4lV03F+dEYu0W+f2vjjgcyz+z94RkKyE2GodKJbMx0uifDP+Yw4py2mqD7quV9mrmLzE9mz8tiuhXrWgvQK9A6BaUBeg80rJRYjrbK1EyXtGWEWLhvp1a6JHma16mrWm+WVaTbc+Lcr+zNmx5rWWSDl+t5gov1OeqhagpavElf9NZ0701JziIcVWQpaikdIJJCfAUkRoCgtOxe2W9t8zvlduY1yUhJs/MV+rjNc/1jyvdHs4+AqZH1N21/hO2bt4NT92OJ3Flk2UIoBRAaV/VNlPf79h+jVwO5NIaZZQww2hlhoBLTLaQhCUjgEpTYAVUSuaoL0BegV6D1VAqBUCN6K87yNLga+NBwvufstOMnLfYR04yepSmSBozI+JTfklfxJ+kV53MafDOY3S+16Lz/AL1PbtP/AGU/Wv8Apy1aVoXYjpUnQpOuorS9tjFzeybeF6i5AJ4XtagARc+FVHXuxfcI4+WjaGVd/wBFKWTh3lnRp06mPr91w/B+lpzFdfL6v7ZfM9d6fmPep/8AXn5u9V1vlTFUFAUBQFA6AoCgVAUBQFAqAoFQKgKBGiFQKgKBa0CoHQeDP4HD7gw0vCZqKiZi5yC3Jjr4EcQpJGqVJUApKhqki41oKRgslkMFlI2wd6S35KXj/wDiO6S4tlc1CBpEkutlNprQ5k2eTrbquDa24VbfdedxO32Hmclu+LjvmGVttw8kGnniVpKQWkNqYkL48PeNbK3rnMx+Qpe5xP3hjcU1srbmSZzmA9L9h7xmtjDR45SgJJSiUDJfYdSLONegUqTzvrWu08UzI6xjTlP2bF/a3y4ynpJ+eEMrMf1re/6RcAX0X4dWtSEegmgL1QtKgTrrTTSnXVpaaQLuOLISlI8STSZFW3PvrD4jCvZWdkWsNh03QcnI/wAVarE9MVggrWsge77pP6Nta5LcxNpxTb4tvBEep8sdwv4jszmPmMXsdD2GxZ92RmH3OrIyE2tdTtz8uFfoqKv0vu1KctWs8Vvusy4rW2RshxWZ6nuhTqnSOokLJJBJuVWOoCr311rqjLVOOx5aqGASbDUmg+ouyX8LWPk42NuTf7TqlSAHYWAuWh6ZsUrlKFl+9/yxbz8KkbR9MY+DAxsFqBjYrMKCwOlmLHQlttI8kpAFZRCM97UCveqHegV6gRNUFzQeyoFQKgWlBE2ItRWozuGiZXHvwJiepiQnpJHxIUNUrR4KSdRWNqxaMS3aGvbSvF6+qr5t3bt+VjcjIjPi0qIel0gaLQdUOpvyKdf9leXas1nEv0PluYrr6cald0/pPbCtKI9nnUb0eokK8agkCEgG1vZVApV021Ch7wINiCngoEai3LzoxxHbufSnZ7uL+9OHOPyKx+8OMQBJuReQz8KZCR/dX4K9or0dLU4o8Xw3Vun/APn1M1/jtu8PB0KtzyToooHQFAUCoCgKAoFQFAUCoCgVAUCNEKgRoEaKKIVrcKBX5cKodQa3cO3cJuPEu4jNxEzce6UrLRUpCkrQepC23EFK0LSeCkkGg8uC2XtDbyi5hcNEgyFX9SYhtKpK783JC+p1Z81KNMDddalfEb0C51QidaAuaCj90O8G0+3cJtWTK5uXlAmBhoxHrOWHxOKOjTdyPeV/ug2rGbRCxWZnEPnTMfxa79kz3FJxOKbZAIiR3EyHvl1/dWT6iG3Fp8VI9lq1TTj2zuZz9uztcn3fuzdG78srLboyS58yxCGbhKGUA26ENpAQ0nS9kp146nWsqx2QYxvWftf2U3r3CdQ7j2f2bt9CrPZuSkpaFtFCOji6vT7vPipNZR4b0mc/B9c9vuzHb/Y+Ldh4+AifKmNFnJZGclLzshC09LjZCgUoaXc3QkWI+K9WI7WMud5f+DrYUzcPz8LLTMbh1q63cOhCXVC51QzIWq6U+HWhR86s7SHScF2c7V4Iwl47bML5iBrHlvo9d/r/ABrW51dSr6gn4eVqmBcyok3JuTzqoV6oRIoDq86AvQF6BE0Ebi9BsKgVAqBVQiKisTieoUFB7l7SOUgfPRG+rJwUkpQBcvM8Vt+ZHxJ/prn5jS4ozG+Hs9H6h7Gpw2/jvv8ACeyfN8/5OGGHUrSn9Q6OppXD21wQ+3l4FXSL3sTp9VCJyDblx8eX8hUAFKtxPPWrA9mFzWTwOYi5nFudE6EvqR1X6FpIstpwDihadD9fGs6Xms5c/NcvXWpNLbp/TxfWmz92Yvde342axxs297siOSCth9P+Iy5b7yT9YseBr0q2iYzD8+5rlraOpNLb4/GW6FZOcUUUBQFAUBQFAqAoCgVAUBQKgKAoEaIVAqBG1AqBcKoKBgVBFXhVCoCgAhSuAv51BU89u1t6THwm2spBczUiUI0xxt1qQ7BbDLj6nFMJKvfKWSlAXpfU34VlwTas4nGPNYl5lbL2M5DXFyGBjZQuuiRJk5IJmSHnwCn1XHXQVE2JA5AaAAVhFIheKXnPbvtUTdWy8N4f9Gz/AOjWWGOWVnY/bJodLe0MOhI5fJMEfUU0wZWNmZHaZbjx0IZYZSENMNJCEISNAlKE2AA8qYMsomIPA0wBckAaGgaJAPsoJeqPH20EvUSRprQAcBoGFi9AdY5UB1+NBEua2oIlZuPHlRG0qKKBUBQRNBBXGisDzZ4jQ+IoOId0dliBMVMjotjcgskgcGJR1PDglziPO4rz+Y0uGcxul9n0Pn/dp7VvXSNnjXzj6OVPsKZcU2vRaeX8vrrQ9yGMhITp9fgeNRYQt4G38udAWFtb68b+Wv2UJWftx3Bk7H3B84Qp3CzOlvLxE3J6RwfbH/Mavf8ASF0+Ft+jq8M+Dy+p8hHMU2euu7yfWEKZEmxGJsN5MiJJQl2O+2bpWhYulST4EGvRfCWrMTid8MwogoCgKAoCgVAUCoCgKAoFQFAUCoCgRvRCNBGgZoFQI0CvpVCJoFcXGtvOg5q7v3fOX3vlNl4WBjtvT8YlL5mZpx2S7KhuFSUyYMSOG0OIuBcl73SbKF7ipI9bnawZRPqb03Hld0BQ6XYPq/s3GKsb/wDRwvT6h/7xxdBod8duIsHJ7YyHbqFB27u2I9JRCWyylqNIYbjOPORpSEdIWh0pCes+8nqvetlaxNbeHmLDs3eULduPkOIjrxmdxjny+4MC+f18KQOIPDraXa7bg0UPMEVhEjdqSoDzqoxlsn20DS2b6/VQTSkg3oJXUDppagyJWvxoJdZoqaXCB+agmHD40AHNPOgn6l+dAivxNAlOWI10NBH1RflRG7rFSoCgKBGgiRQQIorU5zEQ8lj5EGYjrjSElKgOIPEKT5pOorG1YmMS26GtbTvF6zi1XzhuzbkmBMfiP/8AVxD8dtHWj8DifaNfsry70ms4l+hcrzVdfTjUrunf4T3Krcf0fz1JdBWPAC3mfKkEkbAm54+VQY1C6bA3t4/Xb89VJdP7Fdzv3fyCNp5p7owc5z/6W+4dI0lw39Ik/C06Tcckq9pI6+X1MfbPyfO9a6dxxOrT1R6vGO/4/wCH0lqDXY+TFAUBQKgKBUBQFAUBQKgKAoCoFVAaIjQBoooFRCoEo2oI1RE0ETQVbfmxWN1Q4zsaUrE7lxKzI2/nmQPVjP2sUq/Gy58LjZ0UKg0+08/D3CchE3C0vbO+sKEjcEeNKXGSpAACJrCur03Yzg4FYPT8J5E5VvMbN4083uJhBunHJxOYc3u/ilPdWOw0BcqVaUz6XvTI5RBslViSrpsONZ+5XhmMbZMMUnafcjcm9cZvJGPg7BmQApiS6t/9pTp8Qkf6eWzHDcYtqCfvOFSTax0FtO9XSnW0kkgWF7gCs2LF0WNAwigkEA2oqQQL8KA6BxH10B0HW1ABHlrQFteAtQOwPCgXUR7OFBEqVqfrFAvUNvOiMfqacvZQWSsVOgVAUCNAqoiRUGJxAINFUbuJtL9r48SoqL5OECpgcPUb4raPt4p860a+lxR4w9bpPP8Asan3fx22W8/k+ecrFDbheaSQy6SUp4WJ4pPhrXn5fcNfc2skXubk+N6Kd0jWxJ8PG/s8aCLgIPu+8OP+21EeaVG9VBSpN0rHvcuNWEmX0T2F7puZ6F+62bfK89jm7xJLh96XFTpck8XW+CuZHva+9Xfo6vFGJ3vjesdO9q3HSPst+k+Xc69+St7xBQFAUCoCgKBUBQFAXoFUBQFAUBVESKIRNqAuKBGgV6oiTQImgiTUCoI0Gh3JsLZW55kKbuLCxcrLx4UmI7ISVdKValC0ghLib6hKwQOVBuIkaLBiNw4LDUOE0OlmNGQllpKfBKEAJApACCaogpAPtqjGWwKIj0DjyopFIFqAt4UErCgBbhwoHYeNQIpB41QiBagiRegxGwufqoiKkg68+FqCBHvDzH5qCzViooCgKBVQUCNQY1HjaivNIb6teY4UHFO6Wzm4UxWSjt9GPnq/1HTwakqJ9/8Aqufl9tcPMaeJ4o3S+u6Hz/HX2reqvp8Y7vk5LLZWxIU04PeQdRy+j81cz6GJY7AAqPMajn/I0iDIKuXL+X+yqjEs3F1cOf5P6BSEmGBqXPx0+Pksc+qPkILgejSUcUrTwNjoU20IOh51lEzE5hp1NKt6zW0fbL667YdxIO+ttIyLaUsZOMQzlYIP+E9a90319NY1Sfo4g16OneLRmHwnPcnbl9Thnd2T3wt16zcYoCgKBUBQFAUBUCqgoFQF6IL0CJNAXoIqAqgoFpxoCgiaBGgiagKBEUCI8qCJFArcqoiRQL0nHDZKSTzsL0HkYkwZS30RJbElUVfpSksOodLThF+hwIKuhVuRoJqR/sqiOo5UBbW9Aez66CQJ5mgRIvxoC9qCJtagx89bCiIqAtfgaDFb37UFmrFSoHQKgKAoImqIkGgxqFRWpzOKizoMiHJR6keSgtuoPgfDzHEVLRExiWzS1LUtFqzi0bnzju/bUrGzn4ci5kRBdp3h6zB+FY9g4+deXek1nEv0Hk+arzGnF4+cd0qpbpuR8SdD/LyqOhAjQ6aD+X2VFIDXj9B5W/moMLiDbX4hYjw9n56rGYy92yd6ZLZO52M9ABdZt6WRhXsH4yj7ydeCwR1JPI25XFbNPU4LZ7HDz3J15jT4Z39kvsvC5rGZzERMvi3xIx81sOx3U8wdCCOSkm4UDwOlejE5fCamnalpraMTD2VWAvQFAUBQKgL0BUCvVBRB5UCoCgRoFfwoA8KAoEaoVAjQI0CNAqgKBUCuLUEeVyCbAmw1Jt4DxqjmWO7obw3kqW3292201HgvuQ5uZ3I+mOhiSzbraVj45clFVladXT51Mq9L3avJZ4FW/d25DOsruHMJjj+ysWUK/wAtbTB9Z0DxU5emJHhzfbZ/aklvdXa2C3EyENlLOV2u2SiJlYjdz08+mUi5KHOJPt1YRctpbswm7dvsZzDOKVGcJbfjujofjSEf4kd9H3XEHjyPEXBBqxI2psONUJVgOF6CPL81AcKCJUQLjjzoAKuL21oEo3oiKlAX8BQQUNLighc9V7/bQWWsVKgfsoFrVBUBQRP2+dUI2oMarVBiet0G/wBFFcp7v/sz5eF/5r1/6fpt/g/5nqfofn+muTmsYjvfRf173Pdtj+PH3f4+biGT9D51fy/wX92/C/O3+9XHD6yHmHXY9Xw2+y/89URVe48Lc/brQQVe3veP/rUgl4pFunXz4+N9b/RVa5d1/hX/AHn+UzHV/wDqfUPlvUv1fO3HX6HLo9P/ABP0um2vVXXyuceD5b+we3xVx/J2/Dsy73XU+eKgBegKgKoKBUBQBohGgKBa0BQFAjQKgDf6aoWlQI3qgF6gVAjQKgKBKoImgWnVpxqjk24f/wC4439w7/vFZv8A7h2/+3fs236v5y3/AM5b/A6fe/F7tSR1ZfpdR6Pg5VQk36tL35W41RyR/p/77p/7eW+Y6R/3O/8AKujX0uvp1+f+Lp6PvfF/mVhI6s503Nr9N9L8fKsxA0GM/ZagVEB4nx5UVFVrJ8aIWth9v10B4fZQQN9fDWgh7tuVuXDhQf/Z\',
          ),
        ),
      ),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'enforcement-and-regulation\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_3\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'200\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Enforcement & regulation\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-46\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'3\',
        \'source\' => \'node/5\',
        \'alias\' => \'enforcement\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'157\',
      \'uid\' => \'1\',
      \'title\' => \'Error 403 - Access denied \',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5d0be1af-c4aa-491f-ab7e-d1dedfb69ca9\',
      \'nid\' => \'86\',
      \'type\' => \'document_page\',
      \'language\' => \'en\',
      \'created\' => \'1395240347\',
      \'changed\' => \'1395240347\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'3e69dd26-2c2a-4ea3-babb-c1840323aa99\',
      \'revision_timestamp\' => \'1395240347\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_updated\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2014-03-19 00:00:00\',
            \'timezone\' => \'Europe/London\',
            \'timezone_db\' => \'Europe/London\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_feature_image\' => array(),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Sorry, the page you are looking for cannot be found.\',
            \'format\' => NULL,
            \'safe_value\' => \'Sorry, the page you are looking for cannot be found.\',
          ),
        ),
      ),
      \'field_fc_page_section\' => array(
        \'und\' => array(
          array(
            \'value\' => \'98\',
            \'revision_id\' => \'275\',
          ),
          array(
            \'value\' => \'99\',
            \'revision_id\' => \'276\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'error-403\',
          ),
        ),
      ),
      \'field_featured_item\' => array(),
      \'field_site_section\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'15\',
          ),
        ),
      ),
      \'field_nation\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'4\',
          ),
        ),
      ),
      \'field_display_updated_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'field_table_of_contents_level\' => array(
        \'und\' => array(
          array(
            \'value\' => \'off\',
          ),
        ),
      ),
      \'field_fc_side_content_generic\' => array(),
      \'field_links_see_also\' => array(),
      \'field_links_external\' => array(),
      \'field_child_page_style\' => array(
        \'und\' => array(
          array(
            \'field_collection_select\' => \'fc_teaser\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'157\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'90\',
        \'source\' => \'node/86\',
        \'alias\' => \'error-403\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
      \'field_collection_deploy\' => array(
        \'field_fc_page_section\' => array(
          array(
            \'item_id\' => \'98\',
            \'revision_id\' => \'275\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'3086b205-9de5-4a64-b92d-e900273f64c0\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'99\',
            \'revision_id\' => \'276\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'0b903ffa-14ba-409c-a697-124d524de5a1\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\r\\n<div class=\\"field__items\\">\\r\\n<div class=\\"field__item even\\">\\r\\n<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n</div>\\r\\n</div>\\r\\n</div>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<div class=\\"field field--name-field-fc-section-body field--type-text-long field--label-hidden\\">\\n<div class=\\"field__items\\">\\n<div class=\\"field__item even\\">\\n<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a class=\\"ext\\" href=\\"http://food.gov.uk/\\" target=\\"_blank\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a class=\\"ext\\" href=\\"http://food.gov.uk/about-us/aboutsite/\\" target=\\"_blank\\">\'About this website\'</a>.</li>\\n</ul></div>\\n</div>\\n</div>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'103\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Northern Ireland\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'fea37d66-8363-47ca-907b-4f80d9279ff1\',
      \'nid\' => \'50\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1395146644\',
      \'changed\' => \'1395148057\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'45eeab8d-023a-4970-9674-fe6ace84b0ba\',
      \'revision_timestamp\' => \'1395148057\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'northern-ireland\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'6\',
      \'current_revision_id\' => \'103\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Northern Ireland\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'0\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Northern Ireland\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'54\',
        \'source\' => \'node/50\',
        \'alias\' => \'northern-ireland\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'100\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Scotland\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'992a118e-32b1-4259-bf30-96098982fc0a\',
      \'nid\' => \'47\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1395109826\',
      \'changed\' => \'1395147345\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'45ff34ff-2788-41c6-984f-7cb1d5640c47\',
      \'revision_timestamp\' => \'1395147345\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'scotland\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'100\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Scotland\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Scotland\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'51\',
        \'source\' => \'node/47\',
        \'alias\' => \'scotland\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'203\',
      \'uid\' => \'1\',
      \'title\' => \'News and Updates\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'c7efcd49-a9d6-45f7-90c8-6eb5820c35e6\',
      \'nid\' => \'2\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442104\',
      \'changed\' => \'1395504154\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'6dd92932-f132-4138-8e61-ea7f947389e7\',
      \'revision_timestamp\' => \'1395504154\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>You will also find information about our latest campaigns, consultations, food recalls and allergy alerts.</p>\\r\\n\\r\\n<p>Journalists requiring further information should contact the Press Office on 020 7276 8888.</p>\\r\\n\\r\\n<p>For other contact details please see contact us.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>You will also find information about our latest campaigns, consultations, food recalls and allergy alerts.</p>\\n\\n<p>Journalists requiring further information should contact the Press Office on 020 7276 8888.</p>\\n\\n<p>For other contact details please see contact us.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => "Keep up-to-date with the Agency\'s latest news in this section.",
            \'format\' => NULL,
            \'safe_value\' => \'Keep up-to-date with the Agency&#039;s latest news in this section.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'news.jpg\',
            \'uri\' => \'public://banner-image/news.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'15281\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'5c0a0f1f-acd2-40c4-a6ce-bdcf82eb457e\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'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\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Keep up-to-date with latest news\',
            \'format\' => NULL,
            \'safe_value\' => \'Keep up-to-date with latest news\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'news-and-updates\',
          ),
        ),
      ),
      \'field_popular_links\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'93\',
          ),
        ),
      ),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block\',
          ),
        ),
      ),
      \'field_current_topics\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'100\',
          ),
          array(
            \'target_id\' => \'31\',
          ),
          array(
            \'target_id\' => \'103\',
          ),
          array(
            \'target_id\' => \'104\',
          ),
        ),
      ),
      \'field_resources\' => array(
        \'und\' => array(
          array(
            \'target_id\' => \'99\',
          ),
          array(
            \'target_id\' => \'101\',
          ),
          array(
            \'target_id\' => \'100\',
          ),
          array(
            \'target_id\' => \'31\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'203\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'News & updates\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-49\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'6\',
        \'source\' => \'node/2\',
        \'alias\' => \'news-updates\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'206\',
      \'uid\' => \'1\',
      \'title\' => \'About us\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'8c2b6d30-0d48-46f2-8918-b1ed9d47c24a\',
      \'nid\' => \'7\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442261\',
      \'changed\' => \'1395507611\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'8502d102-914b-44f9-b355-29f3c237035b\',
      \'revision_timestamp\' => \'1395507611\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Everything we do reflects our vision of &lsquo;Safer food for the nation&rsquo;. We aim to ensure that food produced or sold in the UK is safe to eat, consumers have the information they need to make informed choices about where and what they eat and that regulation and enforcement is risk-based and focused on improving public health.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>Everything we do reflects our vision of ‘Safer food for the nation’. We aim to ensure that food produced or sold in the UK is safe to eat, consumers have the information they need to make informed choices about where and what they eat and that regulation and enforcement is risk-based and focused on improving public health.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Food Standards Agency is an independent government department responsible for food safety and hygiene across the UK. We work with businesses to help them produce safe food, and with local authorities to enforce food safety regulations.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Food Standards Agency is an independent government department responsible for food safety and hygiene across the UK. We work with businesses to help them produce safe food, and with local authorities to enforce food safety regulations.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'about-us.jpg\',
            \'uri\' => \'public://banner-image/about-us.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'6719\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'664c5f9e-abac-471e-adb7-d41761e08be6\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'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\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'about-us\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_5\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'5\',
      \'current_revision_id\' => \'206\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'About us\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-44\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'1\',
        \'source\' => \'node/7\',
        \'alias\' => \'about-us\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'1\',
      \'uid\' => \'1\',
      \'title\' => \'Home Page\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'3ab80956-ca1b-42e0-a8b2-19284f6a1990\',
      \'nid\' => \'1\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1391441873\',
      \'changed\' => \'1392978505\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'9aeebc91-574a-42ec-8b2c-8bdf4e1b5493\',
      \'revision_timestamp\' => \'1392978505\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Welcome to the home page.</p>\\r\\n\\r\\n<p>&nbsp;</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>Welcome to the home page.</p>\\n\\n<p> </p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'1\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Home\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-50\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'0\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => FALSE,
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'156\',
      \'uid\' => \'1\',
      \'title\' => \'Error 404 - Page not found\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'0\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'5fcc8200-b02a-4aa5-ad33-1365b1ac46d1\',
      \'nid\' => \'85\',
      \'type\' => \'document_page\',
      \'language\' => \'und\',
      \'created\' => \'1395239969\',
      \'changed\' => \'1395239969\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'c9206553-dfb6-4cb8-978f-5873ea0eb605\',
      \'revision_timestamp\' => \'1395239969\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_updated\' => array(
        \'und\' => array(
          array(
            \'value\' => \'2014-03-19 00:00:00\',
            \'timezone\' => \'Europe/London\',
            \'timezone_db\' => \'Europe/London\',
            \'date_type\' => \'datetime\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Sorry, the page you are looking for cannot be found.\',
            \'format\' => NULL,
            \'safe_value\' => \'Sorry, the page you are looking for cannot be found.\',
          ),
        ),
      ),
      \'field_feature_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_fc_page_section\' => array(
        \'und\' => array(
          array(
            \'value\' => \'96\',
            \'revision_id\' => \'273\',
          ),
          array(
            \'value\' => \'97\',
            \'revision_id\' => \'274\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'error-404\',
          ),
        ),
      ),
      \'field_featured_item\' => array(),
      \'field_site_section\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'15\',
          ),
        ),
      ),
      \'field_nation\' => array(
        \'und\' => array(
          array(
            \'tid\' => \'4\',
          ),
        ),
      ),
      \'field_display_updated_date\' => array(
        \'und\' => array(
          array(
            \'value\' => \'1\',
          ),
        ),
      ),
      \'field_table_of_contents_level\' => array(
        \'und\' => array(
          array(
            \'value\' => \'off\',
          ),
        ),
      ),
      \'field_fc_side_content_generic\' => array(),
      \'field_links_see_also\' => array(),
      \'field_links_external\' => array(),
      \'field_child_page_style\' => array(
        \'und\' => array(
          array(
            \'field_collection_select\' => \'fc_teaser\',
          ),
        ),
      ),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'156\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'89\',
        \'source\' => \'node/85\',
        \'alias\' => \'error-404\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
      \'field_collection_deploy\' => array(
        \'field_fc_page_section\' => array(
          array(
            \'item_id\' => \'96\',
            \'revision_id\' => \'273\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'2db50b4b-21bb-48e9-8889-6ed50e4db43e\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'This might be because\',
                  \'format\' => NULL,
                  \'safe_value\' => \'This might be because\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>You may have typed the web address incorrectly.</li>\\r\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\r\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>You may have typed the web address incorrectly.</li>\\n\\t<li>It is possible that the page you were looking for may have been moved, updated or deleted.</li>\\n\\t<li>Our website may be experiencing technical problems and the page is temporarily unavailable - please try again later.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
          array(
            \'item_id\' => \'97\',
            \'revision_id\' => \'274\',
            \'field_name\' => \'field_fc_page_section\',
            \'default_revision\' => \'1\',
            \'archived\' => \'0\',
            \'uuid\' => \'73f80dd0-8e3d-41d9-ab97-9b6ae5101e07\',
            \'field_fc_section_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Please try the following\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Please try the following\',
                ),
              ),
            ),
            \'field_fc_section_quote\' => array(),
            \'field_fc_section_image\' => array(),
            \'field_fc_image_position\' => array(),
            \'field_child_pages_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'More in this section\',
                  \'format\' => NULL,
                  \'safe_value\' => \'More in this section\',
                ),
              ),
            ),
            \'field_child_page\' => array(),
            \'field_fc_related_items_heading\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'Related items\',
                  \'format\' => NULL,
                  \'safe_value\' => \'Related items\',
                ),
              ),
            ),
            \'field_fc_related_item\' => array(),
            \'field_fc_section_body\' => array(
              \'und\' => array(
                array(
                  \'value\' => "<ul>\\r\\n\\t<li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\r\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\r\\n\\t<li>Use our site search.</li>\\r\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">&#39;About this website&#39;</a>.</li>\\r\\n</ul>\\r\\n",
                  \'format\' => \'full_html\',
                  \'safe_value\' => "<ul><li>Check the address and spelling, ensuring that it does not contain capital letters or spaces.</li>\\n\\t<li>Return to the <a href=\\"http://food.gov.uk/\\">food.gov.uk home page.</a></li>\\n\\t<li>Use our site search.</li>\\n\\t<li>If you still encounter problems then try <a href=\\"http://food.gov.uk/about-us/aboutsite/\\">\'About this website\'</a>.</li>\\n</ul>",
                ),
              ),
            ),
            \'field_fc_science_file\' => array(),
            \'field_fc_image_caption\' => array(),
            \'field_fc_files_csv\' => array(),
            \'rdf_mapping\' => array(),
            \'entity_view_prepared\' => TRUE,
          ),
        ),
      ),
    ),
  (object) array(
      \'vid\' => \'199\',
      \'uid\' => \'1\',
      \'title\' => \'Business and industry\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1e6136a9-ce29-476d-95ed-f2e8dfc1c3a1\',
      \'nid\' => \'4\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442166\',
      \'changed\' => \'1395490337\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'cd92ac88-8d94-4bbd-b4fe-5c1367140ab4\',
      \'revision_timestamp\' => \'1395490337\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>The Food Standards Agency is concerned with the whole food industry &ndash; from farming, food production and distribution, to retail and catering. It addresses food safety issues at every stage of the chain, providing information and guidance on best practice and legal requirements.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>The Food Standards Agency is concerned with the whole food industry – from farming, food production and distribution, to retail and catering. It addresses food safety issues at every stage of the chain, providing information and guidance on best practice and legal requirements.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => "Whether you\'re a café or restaurant owner, farmer or butcher, this section has all the advice and guidance you need to produce safe food.",
            \'format\' => NULL,
            \'safe_value\' => \'Whether you&#039;re a café or restaurant owner, farmer or butcher, this section has all the advice and guidance you need to produce safe food.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'business.jpg\',
            \'uri\' => \'public://banner-image/business.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'26705\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'bbfd5e7d-9172-4c47-b1a1-df6255258bc0\',
            \'field_file_image_alt_text\' => array(),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => NULL,
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'/9j/4AAQSkZJRgABAgAAZABkAAD/7AARRHVja3kAAQAEAAAAPAAA/+4ADkFkb2JlAGTAAAAAAf/bAIQABgQEBAUEBgUFBgkGBQYJCwgGBggLDAoKCwoKDBAMDAwMDAwQDA4PEA8ODBMTFBQTExwbGxscHx8fHx8fHx8fHwEHBwcNDA0YEBAYGhURFRofHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8fHx8f/8AAEQgApAHOAwERAAIRAQMRAf/EALgAAAIDAQEBAQEAAAAAAAAAAAUGAwQHAggBAAkBAQEBAQEBAQAAAAAAAAAAAAABAgMEBQYQAAIBAwIEAwQFBwYKBgkFAAECAxEEBQASITETBkEiB1FhMhRxgZEjFaGxwUJSYgjRcpIzJBaCorLC0kNTNCUX8PFjc4Oj4ZOzVGQ1RVUmw0R0pScRAQEAAgICAgEDAQgCAgMAAAABEQIhAzESQQRRYSITFPBxgZHBMkIFodGxUmJygv/aAAwDAQACEQMRAD8Ay3vjHWE3cDSXQUyTxxGrEbiAtDSvOlNdKzKgf05xE677adWG0MQpBIHvA1r1hlJH6L5+S0a9s1kMB8sEoVirPuClajx46zhQmXszuq0aVN0qSwkrLGxNVZeYIOnqmVGxm7mEcUiyiSNxU7gDwB0kFe57ty8EhSeFGQ8iNy1H1HWbFiSxzsmRmW2ixk1zO9dsUAMrGgqaLSvAamFwtR5LAwT9DIwz2Ui/ErIVI+zTCZrZcB29gL/sbH5Cyeb7yOYi9RmDsyOwo4b2UpqyFBML/EDkLFYLP8HhnAUIn3jByBw5Ctdam+WbofLT10v0gZ7jtadFVQ4IeRS1TSi7o6E8dbyziitx6wdk90Wclpme2pxaKQs9ncpHKqug4naaEH8us5/K2h3dXdnbOTwWKsO3JntYrOVVW1RWh2QqhAUU4bRqpUeNCEVLFz72J4/WdMII9BuSqCTy0VKLZxSq0px1KqC6WQMKcAdZVSiircxcyGkUUrT9Yaw0hbG21x2xkk2hkFzC2zmAQJQNNiMnNlb+aOWzWQq7DdG4V+fsNNc7m+VdRxpbtWC8vMef3gxT7RUamBdh7w7hs7lLdLuDJBtoRpEFCW4AFhQjUT1M1r3neRcMpgXWnOW2fcPqBr+fVZ9RzHd6dmXBCSXD2cn7FzGy/wCMKjTMZutNWPXF3qBrK6guQf8AZOrH7Aa60i8cZGG8y0OmBWyOER2SaBxFcKAN/tFa01ZcLLgpZXv71OPc8nbPaEMInsSnzd/eqjxAyIHVF3+XirV4AnVu1vEevq69Me29xDTiOz/UXLrcR95d+36uqwv8lgxFZJsmZlK9VY1J2shHw6l67fN/ybnd16/7dM//ALC9l/Dt6RCnXxVxfSE1aa4vLjcx8Sem0Yr9Wsz6+n4d7/2nffnH+H/tal/hs9HZVITCy27HgHju7kkfRvkcfk0vRp+DT/te+XOZ/lFe3/h6tcP952j3Vl8LKDXYZRLCfGhRBBX6ydefb6c/42617uv/ALyXju6tOyf+f9Sr3Bb5uz7iuLbP3Md7lkSL5i7iUIso6YCNtCpQ7QAeHPXTTXaa42ua+V9zfq27bt1T1674l+P7V9jmUKNaed0bsgVHvp9mplVWS4mbkaaCtLXaWdiacSdQZt6hZR7gQ2EZpGzdRx+6vL7TrWsCBkYayVpxprcQOMNDwGqOelx0EscPHQMHbse2V/fQaDQcRF5hqIZrK33sNC01Y7H+QcNakYtE1sOHLVTLr5H3aJl++R92hlRyFtsiY00ahVnj8x+nWa2rNF7tRUbR6oiaPQRNEdBC0Z1RC8eqIDH5hojTr7027ejmC5y0guJpZAtq0o8yb7C5QEcQR94in6ddPLN4YfbXDdvR4y7ymEEy3KkwXDl9s4K02VXgWHOmimC+7su7jD2CduSzW2TikMk1k5PR2OAAq7jwZTqJgetLSV8VlMhlcks97HHFcvJ0zXfMwSSOSpJqvhTnrUthZMMj7p7flweCsb2PJQz/ADLTwLbRBg4EUnBjuA4MG4anhAC1t7a9srWS4m2vCTGd3m4A1Ap9eo09Cfw/dvYC1zthlVZILuXdCixmkgaeJ1owZacR7NS3hWF+quElw/dDYuO/GVRQBA6JRxuYgRsBWr60xry9N+m/Y9zhfT/D4TNBWvQk73UEZ4RGV94jY/tKH81PHWprjybbfgyYTtvtXt+0aPEYq3sKBKPHGvUfeW+KRqv4V56s48M5tXbCbIXF+GWdhbKChJrwlPFefD3atqSCE+LwsV787kMLDfz346dxftGjsdooqMrDxXxGuVdJGPd7ensWAz6zY1z+BZItJYr/ALFgavAf5tfL7taiUKbGTByqlgTx4HxGtMrlq17ayxtJI5DcDxJpw1AVtcsXUqzmleB9uiobu6ujN0xLz4x+/wCnWVCrPI3jXkMM3D+0INx8fvFGphVqyuuj2/3QgLSra3trGlT5vNJODX7Nc7VZbm4ds7ygkFzUg8OfLWKodFeXsPGOd191aj8upkw6ad5rlJ5wJSCu4U2hgvgaamQxY/JY9mpFHc2ZP+zlLIP8FtXMTFWr+QXFoUFx1/MKK8YV/wCkNLjBJXEGOg6MciW+2QKPvoJNr1944cdWa5ZtXYe5+6MUyLaZS5C8fubikigAfv10swnlqna2fGbw1vdsd9wFCXVF2jqgeag9mkqYc2uK+a7wme4X7hVjkgA4VbYFLGnMginu110alaTj4QrLwrRdtTzoDXWmhy0RweROgIIrezUEoGsqw/1Xt/8A87aRK/eWkBY+FVZ1/MNc9vKgkEDbdYwJxB5ffx0VVuyIY91K6gC5S+EjRW6EgSMqtT9400Gf982VtbdyNBCGH3ETOrNuoSCTQ66YQoXwrIfdqiiyao5WPQTxx6A5gVCz09pGojRsRFxX3jRDZiresqjSFp8x9kOivDw1tzXxZj2aI/fJ+7VHLWegEZq1pbsQNRqEyeE7zrNdFdoT7NRUTQH2HVEbQH2aCJ4D7NBC8B9mqK8lu3sOqIeg27kfs0RuHqh2L3N3Dk8LcYaO0e2spEkvhPJJFMwjL0VNoZSCJGrXWtbipZkj2fpF3zZ9uYrH39lDlJLG6Er7p12xxlWXdEKDzLuB46TZcBkvpbPj7KRHws7yG8E12jyownjD1+6IPk8ppQ+OrlBfO9p4pfTHIYzEQsk0lyWhtGNbgp10ZQTWpotfHV+EvwzP1J9PLe07Jxc+NsrqbJCVVvVAkmdSQ+4FaEgDaKU4aF8suXE39vZtDJZ3CP1Ny7o5AePsFNZyuDD2Z6pP2uIYZ1uLj5bMWOU6aziNClmHWWIoy7t0ivQGtPaNSzI0n+H7tvC9190Z3v8AzURn+WvQcPHdEyiN2LS9QkjY7JVVB8DresSTEbnkrWSWSDI20gkt7gG3vNprtlB8j8PBqbTrcrFiQ2b3SoNhBkjSrfqq0ZI4/UdMrhZupcVhMcjZCdLeEcieDO37qjzM3uGud2/Lpppdrichlte9wdxXVsbS3fG4G2nSaSe4Wk9x0zWiIfgQ+/XPNt/R6PTXSXPO2P8AJV9T0kXD26yAMvzavE4FKeRgQ3sP59dY8tIkSK6MBTqHWkdXmKnkhVU4OPMaalAsW8kDIhBBU1p7SNQXBJE26cjcE/qvCh8dAFitZrjKW8wVgqTxPt/8QE6lWCRtUtrLvtJDVPxS1oB4A3Fxz1z2ajOO4LQvbtKhBQtVfq8NZsQtdBweX2azhUsKkEA/UNQFccimT2HTAKKgC8NRVOZ8qmQEEVmPl3jWSO8YHYWJoVJHEGut+swa65vnCKG8u57p7a5t9hir98G3JWlfLXXTs6/X5c41n0pj24IA/ru5/LrnF2Ee6+7oe1chZ3Rs5LyaeN1iQHpxChFS8hDcq/CBXVvZ6xrr09qC5D1N78uZI1s7uDG205CqbWJS4B48ZZuoa+8Aa8u32d7+j6Ov09Z55VL31WTHiGKfL3+Zyh8y2VvLJI5JPJhGQqj6dTX2vmt7Tr14kmWo9kdySZPFC8kimsrokCSyuJhJKlTw3bGIFfZrWu36ue2k/GEeRwvqFH6hXV7bdxX1p2ld2HzBhXpzLFcoyo8MQmSQpuSrCmum21ctOvW0GyT2GUx9nl7IOkNywje3lFJIbiFWSdXFWozbUZuPE8dcujnOP7V2+9MSS+Zb/lfH+qCO3G3Xow+e76NFP0agCdxAx2hI0oT4ZGkytogUvWVfIvxGhrQV1IFv1JdYu9r4IASIrdST/wB0D+nXShRmVWO4jidBB0YyeI/LoO47WE81/LoJ0tYAeC8PpOgu2x6LBowFI5HnoGG1zuVjVRHKFp+6v8mqzgbxndPcCyArcgf4CfyaM2HfHd3dyGJa3nh/s0/k1WBSLujuNhxvD/QT+TVEv94s+f8A9439FP5NBw+ez9D/AG16e4L/ACaKB5jO50pQ30lD9H8miyFibKZVmO67kP16jopTX+T/APe5f6R1FVzfZInjdS/0joP3zGQI43Mv9M6Dlp7z/wB5k/pHQRmS7POeT+kdURvJdf7Z/wCkdBz1bmlOq9f5x1Rt/wDEqvdcVv2zd9uZu5w04uLmCdrad4eqJI1dQwU0baYjSvt0kyz8sxx+a/iBiZorTvJ5pIvjhnEEzD6d8ZbWvUF170/iZhj897Y3yeyWzgP27Nmp6mA+5709ct4knwWMmP6wjheMMf8ABfV5MA49be83vbiyn7Xie7sWKXMcE00bIR9IbVMLQ9dchbKrX/at7GFPB0uAw+rempkwp3frf2ZfNTIdvXnm+Jp7e2nA95Jox0yNW7Kzfb3cXbWNvO0Sli1sGiuMcYtkW1D95HJGNo4nzBl4itddJeGcc5E8J3Bb47F3kvcVxBiLWGZlnWWRVjZlo3k/aY8DRRqXbHNb10u1xOaqR+qOb7skez7Ax22yiqLjuPIIUt1/7mLm7ezd9muPvdv9v+b1/wBNr189t/8A5nkf7Z7MsrW/GVylzNm84yjdfXhqEPiIoh5UGrNMc3msdn2bZ66z11/EPUZrz1t5gXvPIYCy7dvBmCGgdSscA/rHlpWMIOdajnolZZhJLO68sIPV27nVufv5ezWkGWgcCg56go3lmklG2+caCtDjXbcdnCtSKaivtpZpHdq0Y2UZKqR4hhosRXGOuJ5O+IrW0nujPeWkpESFhwnnqeGsbE8Msz9hlrSKSCTFXibWLee3l4A+/brNilFpoo2pKjRH94FP8qmsiaC4gMyOkvBWB3VBIoa6Btsr5pTuEqTL7XjAP5Nayxhdk6bQ7jHGDUcUPH7NSrH2SCMxKRG3EcSGBB+rSRLQ24QBgAOFGIJPEU92pWo1L00i2YG3P0n8umpX71c7Sm7i7Sk+Wu5bS5xLPkIliFRKI4yHjPv2VKn26t8LpcVjnpplZb7vPGYW4aefHyqzSm4CiTdQbdpHga+IrrydmnGX0+je3bHwb+6fTvK4juRct27dDFwCRQ0cajcHQ1ZhUEHdrnd8f7pl2vVnnW4ab6f2V1e3S5G9kPX2pGWPF5AlAGlag3HhqdU9rlO39sw1aUlkMVG4IdrLwNSCOB9uvY8PyzjNQ2VtNFiLONo0x4HzBepZ7iVFdpGY8XZlILOebE6nXpJGfs9t225VFhNNdHnfeidp1FBe4cbd3dr07cAv7zTSwK1v2vnre9huhbiTotv2rKEY09jeGpihN9S8D3W99e9yHHxGGZ4k+WjnRnUBAgoBxb4KnhrecjPev3CzbRg7ip4cmp9u2mrgciXuL/7HcfY/+jpgdifuUCv4HNQCp4P4fVpgHl7S9VdiSL2bfMkiCSNhHIQVYVBFB7Dq4MBdye9LPJXGOuO3LiO/tBG1zalJOpGJVDxllAqNymo0wO0y/eCGgwEnDhQrJX6+GmEwuW/cvfEZGztx2I/cl1cJdRaD1D9Q4BtXtYH6Un/l0T0Wo/VT1JTl2mn1x3H+lonolHq16neHaMZ9n3Nz/paL/G/N6reqTCn90E+qC5/09D0Urvv71RuRRu1No/dguP8AS0WaBjdy+pDsR/dqSviBBP8Ay6YXFfI816kzSBB249SacYZQPtJ1MLhL3F3D3L21eWdrl7G3eW+s4b6NbcThkEtQYpBIE+8jZSr0qKjmdMGA2D1NvjDIZMcgkH9Wq76Hh411MD8fU27NvvOKHzHsq2zn9uqOJfUq/WBWjsIzK1NynfQVHHx0HTepMxdB+H+WhMho1a+FOOg/f8x33f7g1Pob+XVHp7+LTdF2HhLxGKSQZqFVI/7W3nXn4caaZ5Z+XmyfM5nt/uRUvEeO/YwzG3aQh5FfbIoDRNXzrTka617Qxydu6PVrIWxxrtcXFpJ15JryxlFZulLKJF27kR2BQ7Vrq+0s4pJctlx97Y3UFrdT1x63QDpb3TxpKFPKoDEctFrHO4Ml+FZruu8gmWY2eYEtvDvBRhcQIrtwPm5fRqz5Zl4L3c/qlPeYgWSW0KuSHYmhNRyI4aWqA4e7fMxW8QsmlkWYi7ljlVV6bDy8Cvl8w5146usyWpO2+6+6MXlvw2DK3Xb1vey7LmaNNwG7yhmTh7AKg6xtL8cN9W2sv7p7RsuB9KO2Lmb8QzeSu+5b+m+JryQiDdzr06sTX2Fqe7U/inm8u9+3tJjSTVrNosfRjW1iFpFFEI/lIqLEKeKqoAFdbea3NzRNbm2s7WS8uZkgt4VrLLKQqKPef0aiEeT1WyVzO8uMeJccSwhkMYLgKab2VvMP2hrndrl210lkyT75MrLk7qTLXMl/dSNv+Yf9ZW4ptA4KKeA120uY476etwtdupPb3aTEFFrQj6Tx/Jq1mQ3XMhDVB5awqCStOpXg3P2atE9rLuhkUcGUeU6ypYus1NBkI4pqJ1GG0nkTXRTh6d3JlyneyUo8VzGta8wbmempfJPA82ZYysi8do+IGvLQRT3PXjPWSKRePleNW/ODpkKmYwPbF4CbjD2MjeNYIwa/SADqAPgew+0L/ufEQyYyNYJ7iaO6ijeRA6C0ncA7GHJ0VuHs1nbwQLl7Bwq7RFNeRUXwlD1+nerV0xBVuuxumm61yco4fDNEjflXZqYC1lcJlLdqdS3mNCA210NDz8W1DDTewYpFwNuOFVWh+nSJTcsIddsg3RupSQe1WFCPsOtI83QY5O0PVCWC7nFqtjKVS6ceTa5Bjep4CqEHjry9k+H0vrbz2lrYe6hY5qMz9v5We5lSQh32K1pviTzLQHcd/Ov2a5b6y+Hs0345xDL6e5aS4txa3MPRulVWKihUj9pWHMHV6dvhx7p8tCVgVDV+IcNemPHSb3Lj3u8xcy2A+YmtlhiyEEYJeNnTdEx9u5Kcv061pHHs8ghWSNzG6ski8DGwIYH+aeOtObl2I3A1DACoPA/ZqKqyPU6Clk2K464YHlG35tBjsVu15n8bDuqK3Eh3EkUWFudPp1nXyDMtmsdQZIxQ0/WoddcI/R28B+OaGnvLaYEeRs4Ftn6MkLMUNCC/jy1R6ese3mENvGQoVIo1p5hxCAaDOO2rWaX1g9SL6EkLHPjbGNuFPurSIMOJ8NurJybFjOdsZW87hyVyIpWE1zK4bZwI3UB/Jq2CxadmX44tFLQcTVKADTAtxdn3LuaI1D7h/LphF6HsW7JH3T/UldMKuL2Dfn4Y5B/4Z0wLcHp7f8N0cvv+7OgvJ6f3ZFBG6j/u20yJR6f7AUNd7fFVCNMgphvT/H25Dyxq7c/MNBinr52heZ/1TUQXKwR2OMtbRBsLU88sp5Ef7TWNmvwU4PRvJ8/xZKj/ALEn/O1zsaWG9Icqv/1ZP/UH+XT1Mq8npHlP/ukZ/wDBP8utYRA3pTlU/wDqMZ/8I/y6YRB/yxyfU/36LnSvTOmBvn8V1olx6RSuxAFtkbKXcQSBWTpk8ATyk1qsXzHk7K2VrZZuHpZWyutlus8N9bySyQ7wiyrHvKK6yKy7SCOB1jbDetbB6tdzdr3fqf2R3Mcjj81bvjjZX/yUnzCrMkkgRnWm4eacGjCvA63pf3ZQj9+ySXN3LkobuG+itUhjuJ7MuIoJG3LtYOqUJK+GulrGCf8AOI5Z2kVm4s4BqTQaZBPH9tdv5Ptu/wAyufTrY6Iy3GMMbPclQQAUCg+SpALHgNZy1Zgn2d9FLb3Fk5EXzdNjk0RWRty1/Nq+UjRvU705zEKWmdN5YzpcW8MXUx69JC8UVGZ1FBub2jnrpt07zym3dpbwdvRfP5y47PfLXCibH42cWd7cqSzw+Xekkq08sdOBfkDz1zz8NY+T5/zg7RtQWsbpcg23zPET0RQ0I308x/m6bbfhddchc9xbd5NHe3kzyRhgywqSsXD2R8gffz1y12srt/HMGQ4y3u7WMQQos0BUFBQboxwpX6NIuRtMfZ+RpbdQ4ptrxp7vq1ZSzL6bSwjZnEYWRjXd79ZzTEc22MgvLwK1eiil5QppXwH2nXTS1x31kF0wWLCOptlYJ+2WPhX266OboWWM+XXp2kahvALx46Jl3aYTECifhttKT5vvIxIQBzPmrouRux7Wwln83JZW0drcZKjX1xCio0rAllL05kFifr1lQ+57XktleWvViHFmTgQPEkaigd6kMAOxyyniPr1At5a7jEMjVpThTx0E3Ykiv3JiHpxWa4av0Wcw/TrN8ATFnIpGVGh81OYOlBVY0mRSFoDzropey2PhaZ0py3UOshg7Gg/4RGPYT+fSJTTFHyFdVGaet3ZU19jv7w2SktbxiPLRqKloo6tDMR7EJ2v+6QfDXPs1+Y79O/8AxrOuz+488rQ2tzkLiO1u6NcR40LFI+1FRS7E1IVVA4HXHbEfU6eyY5ma1fCW8Pbl/a5bE7lxcn3WQtJXaRq/qTKWPBi3xU4HWJrjlx7dvg3S+okNlaNc3ELyMpAgtI6GaaWRgkMMY8ZJXYIo9p1013zw4ba4mR7GYi4su1skcu6tl8j1b/MTQkhVuDGNscTc9lvHGkSHxCV5k69umuHj2uS93J3DFHd4m1uAFMkByV/MqGS4WFmEVra2682lupiQB7AdWxBOC/ts3cw2+atLZLhUMk6Qsa20a1AjedSA9OTbfLu4LWldPVMiNx2P2pcw9SAy2hdfu3Dt9R2S1qNZ9Vyzrv7B5DAYy5+YpLbSIwgu04IxpXaR+q1PD7NZswrKPT1Pm+9rdQeMdheSAjnUiNP87WJ5gP8Aqp23g7HEdt3lxaT3VzkGvzPtZpDtikjWPyqQBSp12kz5Z2rN7i37XtoRN+HSwlnEaq+9SSeNVBY1pqbes8xrr023zj4jYe3/AE3tsbZY6G3mumiu4Le5kWSRXCvcUdkSoqF48BrPxR6UoK11pGA9lk3XdHfc7LuEnc97ED7rZIovybTq602aLa4yzNPuxX69XIzb+J2FLL0uhWBmie8ylvExVmG5EilkKnjyqgOkHl2KxyzgGJ5ae1Wb+XUzExFu3tc+k8a9S6G6ldrv8JPhx9mmYYH5sP3FbYS9vd18UYqkMrTuBGWNASFbVtMQvGbvFD5cnfKB7Licf52s5hiI2zHe0IP/ABnIKRy/tdwP8/V4MPWn8K91l7z0ukuMrez30rZS6W3kuZGlZIkSNdis5J27wxp79T5I2VANVWI91Uu/UbMS0qI2iiB/7uFB+eus1qrUMC7eWoO5LdfZoitJAvs1RVkt19mqKZgXg1P1q/l0BNf4jzJxHZOUc14xvLb7ae3nz0zUWE9f4JOEnYeRFedDat+dhrNz+Fy6X1wwBYmTsLIgv8ZENk1ae373TF/Bmvz+tfZpjeOXsbJbJP6xDaWTK3j5h1ePHTn8GVYervpaCN/YN6p5/wDyyxPHl4S6f4Ga+p6r+j0ZlcdkXkDTxNbzsuLtFLwv8UbFJKsreI1M/oco8Z3L6CZm9jsYuwqSOahpcRbKop4lq8NP8FzTbJZelMtsLSTtyP5ZTVYflk2AgUqAG10/k2/NY9Z+A/tS2xHbGezsnbuJ+QxOTa2dYRQRu0UZWQiOp2c/r1mfq0xb1wjxh9Q75rO3W1+YgtZRGqqtJnjNTReHm2iuue22K9HT1+0c+muTuHHR2Aj4Sa02nlxGpLy6YxMNKtL+WCXpvGRIDxOutcBe6yBWBSTzPD26ha4e6EkY419+lgYsBYvBZgzj765JYg+Eajy/bWut6zDlvcriHbZPITzJI/MNbYc2kJCAsPLEBUe889ATsIq3aup4KKH3htQGYiK+7UVMCeNDoM29WYpcJYxZyyib5Pf08iqAlYiw8kpA+FSfKTyrTUVkd13ZHMtQa7vCvDUQx+nuZSTurEoD8Ru2/o2Ux1NvCwrY/Jh7haHmBqB1tMpEsSjcCeVPZqCnPcQlmZnFQa8/DRTR2Wirik95JGpEpg4Aih1RJ1CASOZBFPbojzZ6pXWP7d7xS5wNuLW0eEm+e2FYY7jr7PKq+VPiXdThU6m3Xxl26+2x9xHfeKl6lzdX8txcKA8nXpFDHT9fb408Drz7SvRrtPNax6Uds3WXlg9Qc9A8eOgrJ2pjZQVaRpFKDISxnxcNttweSkv4qdejp6sPP29mePhpuaSV7a0w4NbvKSbbll/UgU77h/o2+QfTr0OLIbLOp3B3hf5sE/f5A4rERrUdKC0gkd5FP6rmFHCt+qZajiNT5X4NsN3FjMo9jaBZshIFt9+2qfMqgeU7RySJXVEX27R7daSmLERxROstxcNNcS8Q3xPIa8Sg4kiv63L2arI73B23adx9t3eGvwUivYigkHF4np5JF5eZW4/k1zrUeSuw473Beol/j8mojvsZa3NpdqTRQ4uIVJU+KsBVfaDrljFaOvqrdCSPtGFWqgsbqbhx/rbmg4/4GuujnuRrtA9pIRxoDQ+wga2w9D26Kt3ircDiq2MNAQPhSMHnrhPDvWnV1pHnz04u42XP3IK1vO4svcbmrxDXbLUf0dNStIx96jNQ0FOHEnjrSMq/itu9/anbVmpFJsjNKQD4RQbf/wBXRXnlbu4iXashUeABpTWcIlyGVysJgkgl3oBsIPHzD6NXCYEJM73Tc2QW4vgbc0C2UXBSfawHPbz0sWYUJMlkNpq5p79PVFC6urhwdzVrpgex/wCHC1W09GcAaUa5a8uG/wDEu5af4oGosahE4JGqrF2T5jubM3Q4iS7m2n3ByB+QazfK0Vhg8uoPrxaoryRDSCtLGKHVFMw+UCn6v6K6DmGzA8BrTK0lt7hqKnW092g/NZVPL8moImx4P6o+zQfjjVIoUBH0DQS22Njik3qiqaUqBoL6IRoLMT0GoAuY7D7PzmWizOWsTdXkcQgZeo6xuoBVS6KRVlDHadS6y8t69m0mIy+f0y7t7TvZbzFSLkcYk221RWPzPRapDSKQoqnJqHjz1PV0naZsd3NFe2qpeKYryI7ZQedV9vt1v1Zu0G57a8vbT5y2cKIFV2VuWxjSvDVmrndhLtexe4uA92oGxep0Aa8jwJp7Tq4PY6M7NLJ4NHB+Vj/6NVlAprFHH4eR/wCXVQRx0ayddBzYVT6Rz1KsfIJDBOqOCoJK1PKvMcdAWTcAWQ8fEagnicOK+OgmKJJG0cqh0cFXRgCpUihBB5g6ivOXrj6TJ21E/dXbcZXCF/8AimOWpFqWNBPF7IiTRl/U5jy/DAm+muYKd24olvKFvj//AF9xqUVMRcVKGv6o/NrIcLK8IiArzGioZr0hm4jWRonabbcRDXxFft1YUdRq8R46qBOczd0kDW2IjE9/LHIYnpVRsXjs/aI1000z5ZtZHYdm4fu/A/hGR6xybBryPpOEmlVmZXSMt5WlQoGCNwbiOBoddbGZWf5v02uezu8u0Ie6Z0vOzsnfW/8AxDzJut0mjFzDcQN54mjD+cGvD4SeNOV0w6+2Xt25kSbI29tHTpwAXDAfDRtyR/VwYjW4yR29R+2I87PBdZKCPNZFmtsTYs33nyyg1loOADENStKkaqMk7c7pxmEku5eB/C89cy2ajjvjWJIv8Za6ny1aM9p5DK9wZee/6j2eMlmmBugu6TbcSb3MW7gTtbYW9nAaeWa27C4rFWgJsbmSV2+KWR6yN7K8FP1chpaGKFgQPBhwI1itPN/rv29lMR6nN3Vb2c34RlcZDbXV+oDRLeRTbQjnjt3RJHSo4+Gs2KW/UdZLyLtiEyDqP27byqTRTunnnYEAfQNa65mOe95C7eCSextkkg6csESQgkkkkIFY8P2tu7XSRm1r/bN9KcphYLh1eUXMQdtjPXYRyc+5dcJ4dq19MlCZ1TcKueHA+OtI84elN8y9mWtwzPuuZ7u54MtPvrqRgaH6dTXwt8tEtMq4YHc/h+wdaRlP8SeQa7fta0JJVFvJiGAHxGJK8P5ur8Iy/HYmwuED3LgEHlXw1hLcDlp2xjJEIDoiVqnm4jVkZ9hK07QxTTU6gYn30H0a0ew7adn4d0MciIVUU2mhBB1qRfZnnfPZ4wt00lsGazkNYxWpUcyD7tLFleo/SuVbD0z7UtPKCmMgdhuoaygyn/L1iRYd7TKIXXkeNfi+vVwM3xMVRLKR5pHLH6yT+nXPLQuqAKOGg4cDQV5ANUU7gURvbQ6ogKr1AK+7QSwrx1UWVjrxGgnRRqDsxjgRy0HQtyRwFdB+6B5EU0H4pQ6g5IpoPwamg+tdwW9u007iOJBVnPIU0Cvlu/8Asx+laR5aKS4uQRCiBjUk7RUgUHmNNWIWu38WMretGyBo0IE0niFr8IPv1uI0XBGMY7MTGgRZGjRfAJCqjboqz2habR1W4PMBKw9ik+QatB2Bt892fAgKPqGoIlYdONhzQUP0aqLmPcicKDTjz0pFnIQSSKy1AfbuX3sOI1FTYu9EsSsf5v1jgQfeNBebhxHA+B1BYikrwbgfZqCSe2t7q2ltbmNZradGimhcBkdHG1lYHmCDQ6lV5I7n7CufTf1QsrdN8nb17HfTYW5apovyUwa2c/txFgAf1loeddQK2EuH2IaH4R+bWQ22tw/SGpVQ3Vw1T79ZVrfbfDFQe9R+bWolS3Nxcz3EcCnp2e3ezDgZB1OmOP7JOu+mmPLnaizWQtu38wL+YUtsThri4YDgGZmVQo97ctdEJVl2/kbrMdt2/cFy2EjyouL2wsbArHeKjyq6vcXLBjEkhlKxxoNw8WrUDPtlZGpdudmdodu3V1lrTHx/NzkFMldl7y/YKo6lbm5aWanKg3DTC5XchmPkcVlMtcNSe5LMgJ+GONSsa/nP16sg8/5W2x94mMu3t0bI2ikJeEDqBHHFd31nVTJSNuPl7uJyUX55CzjmFkco5+w6548tZbhjs3g479MRi2S1htUCRWhUyS7UFK7Vr9p1qVmmiGTvCa8tTZ2cP4dvHzMtwxjk6f8A2SIr+b6SNUPMAuIXTcrrAV3BmO7bT9Vqay0R/wCInMXGO9KMmY7R7hbuS3t5pVG5LeN5VZppPEKNm0HwZl1hXnX1B/DrnOdvJN0WvbXt7DJao77W42wlOzj+0+msmIzbf8F20gt7mysWuIjFeWheSvVajyAnaSAQDRaAjlrpjjlzt5PXZV1NNnsQWJMm4yMFc0qsbty1w1d60+W9uopWnbcI7eCSVzU0+7jZ/wBGtpGH9gr0uy8EnDjZoeX+0G8/n1mBusmfcvAV0lVmfrjKZc/iIGIBisi1P58rf6Ot/CED5S6ZC0fmUHkNTKCdhbTiN2dWrw26ZTgRx8d4ZNxVuHLn+TVyGaKHIjFXvSL9fouYj4hgOHHWpTEZ1ddzZKfHyW1ypkOxgGck8hTx1Juer1NiZmtMLjLQGgtrO2hA2/7OFV/RqRYuWGUZ75I6jlIeXLYjN+jVo7x0O23Wg5nXJpeK8BoInXVFeRNBVlSoOgrGP7wao7iGqjq5vILO3aec0ROeogFD3p1b6MRw0syaPI3D69TKmXIZBrPHPdwW73tADHDDxZqmnDVGVZXurOdx5ZrWz7nhw9pbV+Zgt2MdwhU8UJag8OemvPyzbgT7U9We3IMvPib3PG6sLdAnzFzDNJOZyfi6y1UpTmCurcfBrn5aRaZTDZFQ+PvoLpTy6cik/wBHnqNJJYyvAg6ghoR4aDNPUnL95QZjHyY2ynGGtpFW7vIpumgrUMJUoymNgR5iOGkqYJljk8ri8RePYYcWsGchusbFdwzyXUijrxE7KqEVg8e5W5U+jV4MVofpIvUizEHzDXDxyiSGV1CSGIgrVgOFVbnTW4g5Z5JPk58eWAnkvXM6DnsZQXNPYNuqGyw/sVolw4p1WoyjmIyPLw91NRRayj2iQnmzHQQxqNjg+B0E9qKSqw+gjQFHQSp7JByPu0AW5MlndLcICbac7bkg8EkXgslPY3wsfo0Bywu1lFGPmGoCCqDxHMcjoJI5G5Nz8DqKBd9dn2Xd3b02MnCpdR7psbdGtYLoIyJJw8KOVYeKkjQeRrXDdw2+Rmx8uOlS8tJGguoBQ7ZENGAoeXsPiNYwZhvse1+7nhqMZLt95UH8p1LrTMQ33bfdCgg4q4qOdAG/MdZxV9o07Ei5hwilonV44WNGUjiEJ1qJleyrQ/gy3sHCMWUMsZH7O+OT+XXqc1Lv3GLmIzahggzGOnx0Up5JcMN9uT/hjQpIm7S7b7usML35aPPadz5y2t4r6frMYluIbbbIFQ/Btlt9uszXLWTVge/Z73GrbZXyZewItroHhuCcnp7/AB1YgZ3r3G15jTaRvwfykD36oUlhD2tPoAA58OWkSgzYu2c3Vte3aWMTS7rq7k+GKJQHZ/3m4UVRxJ4a57XHlucnDF+o2IxU8ydsYL8Yku90s1wyCKUyA+VXkk39QMOdFAU8BuHHXzt/uby8YkerX68vk99reslvddyYvA3+LucNe5DcI0niUQlljJ6fWVqAsfhIXjTiBp1/etv7sYN/q+s4a/GUdKryPhr3PMhvbCzvrG4sL2Jbizu43guYJBVXjkUq6sPYVNNMjxh6g4u2h76yWLh++ixHyuLtp3AMvRsraOFaNT4qLx9+t44Zt5XNscuOSeeCI3NhBKLaXb5lND5t1Pi2kAnx1fhj5EOyb6+i7gtZY5qGKCUpUA0JiK/52uOrtTF3f3V3jbYLNzY2VJXSyuQ0brw6RiZZW8OKxliNaIy7sHuK9kx62d9dTC6tGW1htFSNIoYkQdNiwG5y4NNMcJ8n/GXWUhZhFIXVACdxrQe3UGdeqt1f3ndUTM69SK2ij4+A4t/na3ngL9pmMjDYuNsbQAgSe0mvDTDGFy27pnC7flkYeNCdMJYIQ923cCdb5IdNB8e7gNXCYFoO/wDMmwPQw3UhZSRKu5hTjuOmKsIMt3BfXtvDGjqXdV+IGu5gKcvfqSYay9PXPdVqslDbkAcAAeQHDSNLfbebs7/KPFHGyyrbzSbiQR8O0/5epSGu2jpCg1hUzroIWXVELrw0FeRNBWKecaqOYQNWo7ntre6iMMy7o25jUCT3XHHZxi2gjEKBvLT9YalBXsHPs0D464fzQDqW7H9jxH1aRSv64y2GdhxC2N0y3dnO9bOOAP8AMNIu1QrKN5dfACo1fLNZzN6S95WNjJ3DfdOzgC77u2kbbL0lHmYEeUvT/VjjrrdWfY3dp5aytsBHj4YY57os3SyhHneLwXaeRHt9mkiWjtvke4LWMFL6ZraMhmhdtwIBrQbt1NSw9qD9x+pnemKu0mxpMlvdEpby3iK1u0opuRlX4WQEVoePPWbGpa4wXqtmsNiby27idu4M9ezmS0hiAWOIuAOiFUbileIA1mzDWfwfsX+NT9oWkuXtBY5KVWa4tVUKEqx2+UcvLTUUldpZibt/OwyghVaVopw3AdNzQg/XTXSM5Oi2ccHd8kdyywy5ZKY2Z69Nm5mJiPhZwOGlWG7H313k5R14o4re1lMb0ffv2HiV8o501AxW5PS3EipJr9Z1RASA8i+06CxblQanlyOguwSoalzThRRoIpljIK03IwIf3qeBGgGWzSY+ZLctvi527N8Wz9lj4lfyjQMtpdq6VB+kagnEtT7vDQSJNU+7loPNf8VnYi2mUx/fVgvTS+K4/MlKj75VJtpjTxZFMZPuTWKrI8O2dkiupLS+nRLKFZ5ys8qgK0qQilDz3SDUynqILn+7oCFGWvOI4UuHP5zplPU34dPV03dhLNc3lxjGljM6m4jcGAsN4IJrTbpKerRsXfvN2klnMCk0MU1k6NzrGSF+1aHXpjKc5CO7xMVvKfMgRqg8VIoQw94OrEZ92dmDa4zIYudgi4TKXrBjwAjuj14vt67akWqd5dStkjcu3nm+MjxA5HWa1F8BSiSMa04ivt1qM0Kzd5fx4S8ksFVr8Iflg3BQ9ef1DUyuC9hbPL9wi1iukDXK0M6rxUyjhX2cNfM+19j4ezo6W59ldhxY+FJClZCBurrw66Xbmvbma8GvNdi2HceIkxt3WKT47K9ThNbTqaxyxtzBVgD79eidOXPbswv9gdx5S/tbOPJIvzrx3FvkijCiZDGyrbz0X9mYEOtOVPfr1fX2uMX4ePu1xRfvvuRO2ezsvnWZFextneDqkKhnbyQqxNKBpWUa9Li8adyiTHd25TH/ADceTe3n6U90hotwwiQM6mrEeavt1qXhmzkes4b3J2yYvHWwF1dwLFDEW8pcrRiWHIfVq7XhmTkx9oem3f6Zqv4YCFt3oetGBxKjmxGuUdRLvLtDvrG9n9xXV7i2SEY66QussL/1qdPkjk/r+zRWXjsbu6z7htrmHC3rWl2i29xKkLOEZRWGVtoPAfCSfDWtWaZ7WPuNKmXHXsbNQSD5eWnA+5dRWY+olxeN3VcbopYyiohDI6kUQe0a3PDNUbZrJrdEmdR4leI46MCtvj8Uyp94u48/NSlfbomRGKyxzWZhZhuV4umQ36vUFQRqmTn2hicZPgo7CSURtcQGMS1FQJV4kfzS2ta0+WYYzCmx70tMbPXrW14kUleIrHKK/wCTrFdGvXl6hkY+FSRqKY/TACfK5OcUIitAg+mSVf0JqUajFHRVHuGsq+snE6CNk1RC6GmggePQVdn3g1RXilk2qK8BwGrWXF3di3tpJTzVSR9OoMzyF5LdTvLM5diTSp5fRrNUNfN4/EXIyGSmaGws06k7oGYkuRGi0XjQk6s8jROzu5u2Xyk6RTrcS/g75K3WKj7omMfJytUNH404+Guk8sXxQDvm9yPcCRXMw/stsKR2qcI1X6P063WCN21ZXsN+qLCZLQzpEsgYARuysy8K1oyqRXWfZqa5at3X21BZ4+Bbe43vIodgpDCjCo1pnaM3SS4uZkw3zIto725jjZ5BVY5alFkp4GjFeHgdYtwuszWrdoemmB7VBuEUXWWNRLlLnaGFeYjBNIx9HH365x1E8tlu3YLdxe5aygI5iS5iB+zdXVMsKz2Vs7m7uPl2Se2eR9k0RqCK8KEa3K50z5XO3T9q4j8QVoru1ntZ4GbnsLgqa+8CulbjVsQphsg5FDIzOfpc10BizuNyyKTUV4aD7JIA9QedCdBfjTZCpYijeOpKPqy1OxRxPj7BqiXmQi/COA+rQRT2aXULpIacao45qw5EaCvib+SC6+TvPJMOR/VYeDL7joGIFTWp4Dx1B+Eq7gqsK8qaCh3h2zZd29p5Pty9oI8hA0aSEV6co80Uo98ciqw+jUsV457fgvMXje9LC9j6F/YQW1rdRN+pKuRiVx9q8NYopSXAkZaGpAA+vx1mrG74Ev8Ah1qv7qin1azCgc1ybG/ugkh6d8/WSInisqij7fcQK69mcOflB+NOr7geBJFPdqex6lLMYDHZnJZCwupZobXIpBcs9uQrdW0YrQ1BHFZR9mnkHMzZwx28L26HpQgJWpY7aUqSdWxNUUcvUsdjHa8dTx4VUakaB1S8zlx8lYqxta0llXm3tC+7Xg+z9nHEerp6LeW19hdi2uNtImaIGSldxFD9uvDppdrmvZb6zEaFBbbfLGlKc9erXVxuy+AIlWvxMRrr4jn5ZZ2FmRBm8C0xkKdy5PuW9tZRxjEZuV6BkPgJEXye3U6Lzf7/APSM90VP4vspPaemFpaordDIZW3iunAqvTijkuAp+l4Vp9GvU87zjlOy7vC5q6xBnhuDalDFcQkiKaGaNZopY6/qvHICNWTMS7YXsP2X3JkZ3hxqdSeKGS4dVlCUiiXdI25ioG0e/SzBNpUeIy3dsDGbFZi/t2CjzQXMsbbSeXBhw1nhrA/L3n31LYy2+Xz9/Lj5dqzxXUzSRtVgFDbt3NqacIPY3v7uSMgHNliSBR2japPADzCv1aoccV6h90Qt0/nYWcEhkZItwI5ggUPDx1TC5O8+WvJMjeqzXMpDSPGSo4CnADhyGmWbrFS5s7GJSGshIPAOo5fWp0PQHuvwNVPWwsElOfki4/bHplPQKubzssE9bt5BxrVEiHH6tup7HpVGbI9oBIxZ289k0VOmojUqKchwfV919VDB2nYP984M1n5ZzbGRpbtoVmDs3TYLRV/epy1LtlZK0Pq/w43R45vJWhP7QuBT7YX1MtLmNzPpF2xHO/b3cwvpL9o1njvGI2JFuIK0ijPEt46gPW3qX2rJTZkbF/ouVX/K0F6LvPDTU2S2715bLqFv06CwM/YOOCMf5jI35joPzZay8VlH0pX8x0ETZXGmtZGX6UYfo1ciA5LGbgeuKfzWr9lNUBmzmGgp1r6BDXkXGqyX+6e4+2lQmXJhWCmkK1O7Uoy+49R+1gzBJpZSOBCRk/npqKtdvd04bK3F+XtXlx7xR28yToGVtxJow4imrDB5xOVwWMinyPRiEMdjPZRMpEaxoaHaWI4ICvHW5wxatWN+9zbFvlbRYpI6xM88kisGFQQI1Ufl1rLOC72mubxHcYuflh8s6NCWEIk2F28rAvUge2mudjetXO4MdlrS8nyeOneV7hi1xBI6rGCeTRryXjzGnMTgoZlLjGXUuYztxWztEjlaK2ZHnYyt5HCkAVBHOur/AHpCp3r3Ngu7EsJcQ88V1EJBewTlg7KaFXZwxVzXWdpG4D9r9kZnOZ61xOJSCW8v36cSTOEXcAW4ua04DSXC4GJEmwMLWF/Iq3NtI8bqvmoVYg+YcOerlPLRstjMke2Mfjs1Mkl5NEGtZ1agXaCVhJ8XRTpSNM7F7kbN9r2rzkLkLF/lMkvh1VXyOP3ZR5vpqPDT2xOVMdtcPFExegavw+IOtIvWiFjvfx5LqouvcbF5AeAGpIqa2HTiaVviI/6tBJZzBpN3joOpWKMQPhJroAfcccstnHcW5pc20nXipzIXgyfWDoCmGz9vc2at1BuI4A+I9n0+GgmiyEKzmWdtrcRGPAaAxjrqO4TrROHQ8Kj26lHnr+I3tP8AB73uDuS3j22fcdnYRzMBQC8tb2MNy/bi2n3lWOud8qw7HszyL9Kj8us1Xo2BJIcdZsgNFCE09wrTVkSguVwtzmYGms6m4tx1IigBKN8S/SDrveUhex91bXySFh07iJ9l1F+w/wDIfDWMtYFbrGLFHaXj0WOCdY7h/Aw3JEYYn2LIU1uVmw543tNB1YZk3W+5gxbko9pJ5a2yRL+zsO4e4/w7GQzyYK3YR3V7bxuRdOpoxjcCgj8K148+WvB9nvt41evo6vmti7d7I7exsMf4fa9EIPhbzE/Sfbryzpnl6v5McG1LeOFo4+TPxWOgJp+17h7zr0TRwvY5/EoInMUi9MgHaSwIO00I8Na8M+Q3NWWdzth8li5PkoLsmK5ye7bJFAf6w24oaysPKrcl+LmANZuu204LtNRXC9tY/GQW9vRZFt444LWIKFiiig/q1RB+zz3eJ469GnXNZiOG21tZr/FjiReekct6ZTH+EZC0vNlKiTe5tNp9n+9bvq1tl5nw3etumNt8bncacpDZqEx99DObe9ghHEW+8rIksKk+RXWq/qmnDWZwlmU2R73Z7aazw1q+NtLgFLiV5jLcSREcYmcBFCN4gDjpaazCpiMgsbTEjgQqgezjrLSxmshHLi2jHNrm0U/+u3/5mhkV7BkW77+7ctwofqZO2LA8QQsoJ4aXwCnbV9bXWY9QszModrfCZd43PGkt1dRRhuPjRzrWOWvllU812l/NLGbhAW4GOR0H+Kdbw5UVtu485EFCZC/T3deQgfadMIvJ3h3ECf8Ai1yR7GIb/KrpgzViLuXMyOA92JKhjR0SnBajiANTB7JLjNXwgZ1EUrgFqbSvAaerUqphM5NkrqSKeKKNFRmDpurUEAChPv1mxcicsUXGjD6xqKYe1fTabuazW4gytrZSyTTRQ286uWcQKjO67PDz05aluFghdegPdcZol/i5uIH9bIhofEho+GuO32NZOOf8Z/rW511VuPQTv+OhjtbG5HPdDdJwqaVO8JSul+xJjja5/Ezj+9P4/wBQ/wD5P+pSgmPBTEDgDHNDxPu+8Gu2u0vjLN1whbsT1StD/wDJsulP9kJH/wDZs2tJhFKvqHj/APeFzFsB/tYrgAf0l04OUB7l7p3gHIXJl5KSv3g+jy7tMQzTzYWnpFmmgWbuzI/NAA9GWKC3O6nEbtpHDVkn5Ztpg/5S+mt8/VN9k7wkUGy6gHu4UTWsRn2Crr+Gv03lJNtPm7YHju60EvE/TGNPQ91eP+He0slZcN3fkLBXp1UltUdXpy3dN0rTw4aev6nu4n9F/UCFWTF91429iZSvRv7eVNwPPd5ZRU6vKZiey7T9e8NbJCnb+KzltCKILK5SE7fYOoY/zaclxQbL+sFthbi7wPdWBvcNl0j88EbxXABYVHFSvPTKSfhl993jg8l3A2Qa7vbaAOrxRMoYDaKbfI3wnmeGsbc11njGPlf7iyrdwYuOeaOOG3aQWkdzSURrGSWErkjgAD8PPS1MBmK7USPMNYW0b5SE2fVN7jpoXVmDnzo0oSij4WSta6mVM/ZUV1ge5sZkcct1cZqyuElhxkluB1TxqqskjcKcz4azLs1nVpHbnpdbHLP3B3WiT5KaVp4LENvgt3Zi33oI2yEf0Rresvylx8DHfWI6ljLci3EsKkfM268AKcVkSnwOvgRwOrUKXpvnUi71mtYJaWeUt+i0ZPAXER3xMfeSGWvv1PI2PHOtyQxG0rwdT4NraDkG2lVIJ5U0HEI+YumPEpGafXoLVy5ptU8By0HdixFWYcuNdB9vLjyinNuegguwsbWxQFmVCXA5VJoK6Bfbr4/JGUIrWLGoUCgUn4vynQXnvkeVWdyqnh5lqv0mmgY8EywIemUdHO4shqD9WgUP4k8Ycj6N5aZCQ2Nltr7aBzWKZQ/+IzHWNleTsSGicTzoY4oyCxlUj3jy8GOuPZtxw6aa5r0B2l3Db5vH20UUm6aMq6OinzLHxYU9vD2a4fX77tt63y9H2PrTXX218D95iLaxybZSykK2oX/iNmtVnt1r/vESn441r5xxG3j4a+jXihB9S8cnbfd0GTitlezv4wt/FbgKJafE6U4b/wBYa57eW4Ix3Ftedr5ywx08WUtmhMVtdnepUyxhypXhxQHj7Drz9n2PW4nLv1/X9pm8K+ezU2T9O1z15fSyz2McLy2qyFLaWXeI1WSFKK6jd+tXXG9u2/Fr0a9WmszI0T02zZvMBvyLiPo7emEAYCtBs2jlzGs9V+G+3W8WfJvucrDZ2M0z1t44QWmmKtXn/qlpxr7demR5PIdYXtzetK9ujxVr/Wkh3Civmrx4hq8fp1ZptUu2sXrSxmYlpp2Oxg7wNGGQqvMUO7jTxGuunXNXLffI7hsnBf2EdxEfExkewr/6NaYWHJFyh8OH5dUU+6u3rPuTtrKYC9ANtk7aW2ckV29RSA496NRh7xrMH87bYSovTmFJoyY5QfB0JVvyjUotrTUVfxq1jkb94AfZqD7lAq2kA8HvIq/QkcrasDT6Qp//AKThZDytjNcH2fcRPJ/maUiHswOewvUa/PH+wWUJP/8ALyUYP+Rq/wDL/AKsZIHPhwroJBuJ56uUfmiI5gV9hA0zTDkxJ4oK/RTVymHJhQ+LD2bWI09j1fbGNLOV2hr5xQ1PLjXUtXC217KeJ0U9enzXTd29rdFgPlcVf3swPEBJ7mRCacK+WMa8P39sdVxw69MztGgZTD9y46/vJ8Xk0Ed5I13Fjry33rI8oUyASwlZF20AXdX7Nfne3v8AGu0zj5y900+ZXfbyd4P3HiF7ivLZbQyPPJBbRzwyNSNwsLPJJtKbmFfL4DV6ftaS2a+3P/2wm/XcZ4KP8ReQkh7iwvbdtJ/ZgI7iVeq1d8jFtrKvhtUcfedfotN8deXj21yqYu4zfcXc9l2v+I393ZO1ur435gwqvQjCnpyBqUjj3BRwrrt17Z1jlvMVL6l5DuHsHM9uQWXcF9Jj7mGW/ntYXNTaTXDtHDSQyq22JQNzV8dd7jHCYJX/ADo7r6VWsouuD5ZN8nU219v7W3hrPq1ltuPwl8VCph1jXwFFp/k682vb2X/i4Udte1Lh6FrKONvaQoP5Neia38JheHZTMKmQ2x/bimkjI/okDW/SiOfG3OPtZIou9vkXIJQ3SWt1Q09soDfl1cX8qw899eqlyzjId7C0QMy7bNIIyQDSoKrwrrOdvy1ifh9TPxFq5Xu7J3j+wyzzCv8ANUxJpj9V/wAAK47c9Psvk5sjIMxkLmQ7pSgt7SMtTmWY3D1Os7dk18taabbeBhPTfs9Mb83a9uL1FI3/ADt3PMVB8WSMwj8mvP8A1fPjh6b9O488hOSxd/Yx9O3xNtHbORRbaMyJUcASHLH6zrpr9jWuO3RtFawxuUuHHzKywWAYdZIisLsK8VSgIBPtI1jf7Os/VvT69v6PQfZPbvZtrhIb/tm0WOOZNk083nuw6/HHPIatUH2Gns4a9Om0szq5b62XFEJoQQSQKg010ZUrqORsc29ts8QIX2sF/VP0jlqDC87Na4XuEZGOJYp4ZFlAiNCSrbuXv1gegsBcxXePiv4CJLe6AlRweaSDcp+w62Lk90sJ2x/1hHP2aqCVqTb24VfiYVJ9ug/CRnAH6w56kEwnCLtqannqiFWMrhq+VTQe2ugvsN9sygVatSfE00Ae6dY0dXXeGBUg/DxHjoBtgtxsEEg+GgRh4r7/AHjQFLXfDMjLVem1QBwr7dA7wPFfY9lR9gmRkD0BKkilaNwqPfrNV4iymH7hlzWSHcD3F3lIriSK8uJCZJJJom6ZZjUBRtUUHgKU14ey+vl7evk2elNjmV7ipBexY+ytkM0kxKkQmhBJLbfN7uXv1n609uz2nx5Xv3xpj8vQ9qcLkJFW4aK8kPCImSIt9Ip0yK/u6+h/JpeJY8Prfwy71vt5rHqxWzM0dha/O3kDEOkMZbpQAE+Zd7bjtryX2a4fY38R36dbc0s+lNot923mIIJaXtzZziI1pSSSJgvHkDUjXj2v7ns65+1P2JaQ5z07uMHdQOgu7QRzzLSsUpqQQn7rJU6mebh1114mTZ2BFLjnvO2J5xHlLZjHvoWHEK0UzAftLtPPV04uF2n7c/EaZbWJdelM3WMo8swruPDzeX9X/r19PXX1fI339ltLOO3bqL57gbeNSVKoPIxP6zAVU61lhbefpuLhWPmA3sf2v2gPZ4aCCEwWs1vNbgQx3U/RktQKAyyAszIAPduNeVDqKNS/HE30fn0FnmfeNZH8+vU3tmftTv3N4ub+oF3PcWZJ3N8tNM5iL0/Wp/LpVBBJssor6XyWczvHFOeCu0dN4Wvs3DUBHG31iIGJnjQM9V3Oo4UA8dQfstNBJDZCORGrcSu211PBYaDkfa+gbfSFv/y27uPCzxOSmB9m2zlH6dPmE8q3a8/Q9Ge9n8by7wVtX+bcTTEf4urPN/uWFNXGiJkYkaI73+0VB0HwuDw1VfAQOHt0yPvlrqD87UUn2aDQe2szjLC/kthazHLY/HY1BdRJXppLbdUrUSIfM9w1RTWdtNdpizMWWzwN5Dv/ALhMsHWjmpbHfEWWRWLHgQShNRTwbXmv/X9OLPXy3/Nv+USert5HlYr27xXWaFOmqKdiFd241Vozxr468nZ/0n19tcfujpPt7ws9+dy4/u/O/jCpNiL7qQOhEUdyqRwRsvTFXiqGLbiSPDX0NPr666enw5bdltyt9r5jtrFdxw5uS+aO8SN1eaKGaOpljaNmEYEqg7WPjz1udUmGfah/qHeXvdHc7ZbHZSxSytLVcfiIjPJDJHbxJ01DCaNfM4JLcfHXXHiJkpns7ImMTi5t/mANzH5u22Bvbu6lefu1MUy0nI+v3ehqLaO2txyBCbvzk63lialu99Y/US6BDZhoFP8AsgqU+wazmriFvId4Z+74XmbubjdzBnf8wOpgwGi8MjLu6swrVh5jX6zphVqOa6Uno2h2E+QyOo4e+ldOBzPe3KGtxc2tmPadzt9nCv2alWDOL7yaEpadsWc2YyaqS87ptjWg4yBfZ9NNeDfrtud7iPf19k1mNJ7Uzen9j3pJlGlyd2lreXEm5RK6mPpbfPG4PA1HLjrnt65/Y7ae2P3HXO5Ht6yVo3mWhBDMgBWviB4/ZrN0luIW4maVL3vHGRWotsfZvKBx6ktFG76+Ota/W2+XHb7GvwYvS/K562W4y1vNbXOPL9HI4JZD884HFZoYqUqu7ga0YVGvX06XT+55uzebGzN+oGAsYo73rp0py0cYNWLdPgwKjzArXjr0ZcSZl/WDesgxsLTyuCqyTxiONeFK7au7faNPYZlkLia6aS4uHMkzks7t4nSI2z0IzzX3bVxiZGDPjaPF74JGIZf8BuXuPu1bkP0lg7MXjbyt8NRxprSJ7WaeACCfzL+o36NUWo25lOBGg4ubig83HbQtTQTWbpKm+IFlfzV9x0E08kyKFQ09p5nUFRYllDQOxVZ/IzDmCeTfUeOgAzm/srmW1uZAk8JG0DxHMMPcfDWkFob0tAjyUqR5iNRR6y7kx9pbIJpgGA4RjizU41VOZ+nWdrjy1rrb4YT6vZ9IO9cjJJjzFHIkVwhhO1pEaJQJSa/FUcaa82/TN+XfXtunFKOF7ssZp5Ly1s5r24GwR28q7IxNxJeVkrvVB8PjU/Xrz7dV1mM+W72TfHB+wOf7kuXVrqK2MbEUhWLaKe5t2/692vLtPw9GukwP2Flh7j09z+e7omcY7JI19knbzuttCy9KCOp3Gqosaj369Omt2vlJZrAf0vxU+IyEUN9YLYtmbaLIRWgJpDHNWkZrydK8R4ctXfXGy9e+dcjVjaW2G7qOPdzBa5JGaP8AemhYQsAf5pj+3WMYrveZkTSyu7P1BsstHbySWWUtIrW4dEGxbm1bpESVoVEke3Z7Tr0zr5m0cv5dZrtrb4aJE4iWaBN6U2lZA26oHEMWABO08COWva+SimvGnDMo80flavAAGm4LQ8uRGkFa2a5uoitsN88i8AwPSQq1C5PPaRx9p0oNWNtLG8PzTrPciEhpQu1d/DcVBrSuoq07Vjjb/pwOgsA+Yj6dQeJf4mBJc+tObhlRlhS2sUQoKkqYFetD+8x1L4a139bkhdxX/wAwljY2tvKMXioOjalo2G9nO+aUinAu/wCQDWOZx8Os1121zn9yGzvMdHEiqVu8xLSK1icBILevDcxk2hmHh4e06lpp1y+biHTDdhYiKwWN3t726PnnmRklG5hyUjwH5eekjO++bx4MnZfb9ti8j3AIIhGX7dvy1OH9YUgH/tDq/LCjZ9s09JMxZRFlRu5bKGoJqRBYyS0qffJpL5Gd5ixlx99b20U5czfEDtahrSnAaoisY8rPbvKrR7Udk4oeO08+BGlqSLVra5eZtqpEx/nMv5wdT2XC62A7gC7mtKqOJKSI35yurlMB0pniYpJFIrDmNtfzE6ZMPjXUSAl5BHQVIaqkD6CNDDuNmuyIbUNPLIKRrGpapIr7NLQ59uXIuO7s68LBory6tYIGAIrFHEUjPED9XadUptk7Tyce1Y72U8fFt3566zmqgk7fzScp1f8Anop/RpmmEL2WYjFHtbaYD9pCD+Q6uaYQsQgIuMFDJ+8jU/IV09kwieft4cZcLNER4x7W/Sur7GEJk7NZlcwXQkUUWPpniD4A1p+XWvaIyvKCVbOaUXUrOgBXiFHMV4KNVBTL4uzgvWEEY2FI3UsCeDxq3jX26YFJmht13SMsaDxNANTCqE3cMEbEWqGVv2j5V/Lx1KK97nLycBbdumAPgQ1NfFifDXP1z5dJceFWwxN3kSZd4AZtpY1Zix9ijnrbB+wVpl8Hj57EQ3GOJmjuo794pIJJo3j27asArR1rrj2dc25rt1911mIv29rPfEdCOe+l4CsayStXkPhrqTTWfDN32vyNTdg932ttFdX2JlsLaQ0imvnS3B4V4CVg1Ke7W9dfxGbb8gl71LSZUkVSkjFI5w33TsP2HIo/1a7Tp2rOQ97+/tL3HX8LtZX8TXEYkgchlKheTDwI1izFMrN3JJNKJZXaRyPiY1OoOIzUcQdBWvLm1jBEkqj92v6BqwM/pB6hYvt/uuKPISCPH30TWb3J8qxszB42kP7O5aV8K61Ew3i49Q+0YWouTt5WBI2wuJTUcxRK8RrWUwlte6bW9o1ohlj+IMNooPbxNdT2XAhBeSz1MJCbeDcNxB+3TItQxLI6iY9YMRuDUoB9A1UFKKXEKACnJRwCqPbqKiYB36cXE8ifD7dVFeZWgl3H9Qgj6tAO7+ks5rXHTtblpmLg3CGhCAAhCPHzNUezV1Slq1v7hoxbq0kat5QeFSfdXWrCAuMgvbTPzvK5eRqPAXqSdrVC8fby1x7HfrWvWXtr8b7ElytohGRwQNwjEVZrUH7+JgP2R5x/NPt1y1uK32a5mfwRfTLtHKf3fnvGCRRuwup5SSAsTALF9o8x9x1x7tm+jrzGiYDFXJxsl4Yy1k4dYJP1+oQVXbSvAn265dentcu++3rMKfbGcmj9Nr5JgGWyt4rK7SdWI+7dVYKtD5izezWuqY2rp2656pUeUyGWyGNx+YLET2cqSPKhFJrJyFkND5tyyBd3sprf2Nc6uX1b+7Bn7xsI77tdMpAm3IYh0yloSNzvDJEY7mNCPi5B/pXUvXnS/py7Tb17JnxeDZBmYMjhLcrKlzHcRrSZCKyIFVl3UJ2ujk+PMV16+nbMeH7fX67fq+zXF3LDvAK3UXFTQ1lccKIi+Zt61H/Vrq8wjZ2T3F0zXW6G3kjUNZsoDPSnxsCac+Kj7dESyWD42UXGPG2BaB7ZfhCjxUeGqDNhcJcIsgNeP2V1mj9PUQLT9pqfRz1RaAO+v06yry1/Fj2fe2XduO7xhgJxd/bx2F9OvER3ULO0W/2CSNtqn2r7xUlZXi7gFeFdKkaNgLCGbGwJcW8cyuWJWWNX5seHmB0A7uvtjtlMvZJHjLWAtbNJIsUSR7j1KBjsC8eGmIWrHZOGsI17wgtg8UMuFihdo5X3Brm9jHkZixThH4azZysvCzD2rDkvSy5xpur6GEdzXF1b3EbB3mjS0S3VmkYESLuVxX2g+zVk8l2xCq3ozBcSJJFnpIJIxRVktUp9sboa+/T1Y/lWcP6J92rKMdhshj7+4vJPJ1RcQtwHM0WRQqipJ1Lq1Owf759Kb3tf8IsMFbvl8gI5ZMzfyTR24eUuESOC3k27Y12MQ1SWrxOp6NXeTy77T9IfUnu/AR5mxawx1jcbvl/nZnLuEYoWAgjlG3cpoSeI4jhqYq5Cu6v4d/UrDWv4he32IkgZgg6NzKrEniAOrDGp5e3TlckrJ+nmdt7WZZbc3F06ERCGaJlqeFSd3IaGRfunH5U+mHaXb+MQtcwXN9f5lYnVXheWQRwq9CCx6ak8K8NJ4M8Jew7S4XuBJJlYGW+d/MpHliQKp4j93holajkMvYWCGa+mWCJQT5viPuVR5mP0alsnlqa2+H3teefuaE3FnZTxWu7ak8myjH7aD7dea/Z58PR/TfmpMjZrZSff3ETwnyq8LK7iT9ZWiJVgF/aFRq7fak+Fn1bflzNhZwU6Ziuo5adKSFgwYkVK057h4jW9e/S/Lnt9fefChPiQCOrAU3EgblIqRwNK+zXecuNlnlV/BbbfXpjhqowHIMrY+ZSPNsb8mtsiN5lOpbWIKhibO3qx5kiMD9GhQC8xkVw4fqMHJJap3cD4Cp4aURGwsIFLOGkoCSSacvo+nXLe4b1iiXdUWOOQON+5UH5OA8dG8mrtlb6HIWdrjYFnv3lAt037C80nAKGNFXj7ddOua5ntcT/Nz2z8Na7ju/UebAY/K31lbqMRE00yTyrc8LW5J80bEpIDv+EVqB79evafXxf3b2/H7Z/7cp7ZziFqb1R9Ts3YlH7iOHw6E1FskOOtU8doMKqzn90EnXzdt5r/AH/h3mtqhaW9plbv8Qt8ncZZ9gEvW3LxA2N0+sXfa1a8h9GnVmefK9ll8eBizxlp8tHbdMxiCogSVmkCVO47VY0HHXe9u1YvPNDMx2veT/LtazRHoSSPIrVjr1E2+XmOesI+2drBb4yG6zVtOZkvFguLS3cMxtGQgToyg/C3E61JPkpH7usshh+5rvFS3xvbeOj20wcbJIpFDxt5eFdrUPv02mCUKgkoDvIWvMc9TKpWliY7V410Gl+ldhb3WDmBbpSm5cxTDnHIFWh+gjnqFaPjMnf2LrHcxIXWm51UDdQ86rzB0yhxxuWRyzx1UMASKa1AXt83IjlFjqzU+I0px4UoDqoPR3kRtFqrRyv/AFnGrH6/foqezUkrcP5I4v6pPfoipkmkYljzb9OtCpnLNZ8BauzbencHc3sVgR+cDSJSqJreGdI94C1NCeVR79aqR+x9ss2WjaRgwLsFPMgqeX265b+Ho6x7M5h7HtbJTxW6XM8dvOGgcVV1bylSP1g1SNeTs2s8PbppLOWf95ZK3wHo3O8XTVshBFbPGWMcydai70UjisYHFfZ4656y1riQXs+4LXGdo2VjFMkt18tGWtw5Xc15RkoV/dKgGvjrp1zEkctpLbcrZgxGG7UybZ9pZr6+Z3ltLUDZaXMblW6u6gNSq8eNeOu2musuWOzbeyT/AIqfb+e7fSSJ7aL53G5C06l5aTxdIx9cmGdQSfhLrUAH2HU7+JmTKdXnFuDhbpYY/DJYWE8hCAm3V5d8giXgdrHj939Z1n6/Dp9u+yPHZXG3OYt8Tjrq3TKzwNezWpYARIjiNpQi8w7MPL+jjr1SvDZ+TdHiY7ZheAhp3WjXe3bu41NAKheJ8NakRYF6VI3Kz04BgD48NMInTLWg8s+5K8NxB/LpgBk7nv4O/bHt2zwdzcYK9s5Ly57kQn5W3nQsFgYhdoYhRzavmFBSus0N/T30Whp5uPhxFNLROFA4+OsqUfV7tS47r9Ns/grRBJe3NsXsk4DdcQMJoVBPKskYFdB4gwl5D0V6gZGqdykcQRwII8CDoN67Sbtx8BjlN4Y51hHViKkEvxJoTw1An+oVxEe8ZUtrpXgs7OCKOStQWk3SsOHs3DVyOuyJLlu2+7GZ13SHHxs54DaJJGpuoeBpy1LeSR3P3LlcF2Bg7SwhMb5e8vZ2t7dT96kThIiF89TUO3l4asSzg19n9sdz3uKGf7rkXB4R0E0URQPfTRniH2colPhu8x/Z0u2Jm+GZ15vA9hPUHtTH2kknbFg92lxJ8vPkJyVZWBqFYvt2qeBHIazrvNnS9fqSM33tk+6b2bHTXEMOTu5Vs/n4nDQW1oT95MXHxOkZc/ztSb2S5S6e20w0jtr1B7WVbnG2e23tbO2jx2PhlmjQdCOKkJgBrvG1KNTkwOvP/UyfD26/U58o+87Wz7pwWLxcGW/D48fThcIaSyEBQS0gjXhxp5tYn3JZj5df6KzLKs/2guBz8NhlMsGspouol3axt1KcdwMTkUZTzpXTfvxOI5z63PNdS9v9sW1st+3dM8llLQwiNNksZRhv6qkureX2U46z/UX8Nf0s/KOXF9n3kcSYzM3F7PNKiK26Oioz85kkiXbuUHijc9Y3+1Y1/S6/lci7VxF3mfwaVytjAOrdvU8VjQyFVc0PIEnbrx7du2ebzXq06pPE4Ebnu42HaqsuKt7ZoYR/YrZ2UvG58pYuKilOAA82uX8etucTP5a9bM8r2EwuLjeNIIje3d2kc5dF4zbgWkVjT7rb7D4a76WWSznLnj8mXuG/weNsNs9sXvOmEhtbELJMzbaBVXyBaH9ZqcOOut01NdqSu3O6cpd4u+kyyM1rj50e4tN7M4iqA7ozeKbgW4cRrn/Jtp4a/j138mmbGxQXkH9us3tLqQr8w5CzRhY2mBjjB2uWEZHFeVTzGuk7+zH+79rF6OvOfXn8PJxyNncQPGI3SR1KHiGArwrXy6+xdo+NgSssat3b2aq5PSVYCzeVTQkjiOXPWL2teglGvbFhHJPkI1uYom6bwrKqSE1odtW3GntFNSdsq+jnPZXtC87eTHQJOJI/vLYRIPu24ijOzecEHjpdrTGCPEI7dt1AZKeVmoAD9Arx1cUzDR2FDeG4m7gZ2VMX/uuwDzXbgiOlefTFXP1e3VZycbLurLTxT20t48kLK7NFMQ5beyPIHHir9NTqhW7hlvMZlvmDsuLC6FbNTQxxmOiyQbGG1WjPs8CD46z6yeFz+XEXc8wjP9nijIFVXaPzrqD9D3vCBW5t5Nx+F7eY0A96PXVHT9z2t0wNrl5cfLX/AFyHafppuU6siLkWY7qZDtntclb+MkW0NT/BI/Npckw5j6Uv9coFf1HUEfl1FsVrvB4WUFjaqD+1GSh/JogXJhLRZAtvLIrngsZAcn6gAdA+9kdu90WeM2JEbeJ5Gkea48ilTTknF/D2a6a6Wue/brDaMpJZIUJa4PIF6LGp8SBRmP5Nb/iny5/zfgTn7nuMZZ42YlJTf2xuEQrSgWV4ivA8eMfPVmsX3qWP1GlidZpLEkHl05AOHtoRp6LOwwY31Kxl3KIzFNFJSu6gbl9fjp6LNzhF3piJxHQSRcPKjpWnv4V1PWte0TfiGPnaq3CkDxaq8T7a6mDMdZaZX7eliRldlZGUKR+2OX26RaT58TZJCGdn3cyFqeJ1vLOF3FR2lvlo3NdqMrsTy8y01y2nDt13kC9ScrkYu27jGYykt3KGQy1A2os6Px9tdp1y105duztxMTyM+nfpP233ZgFy3dcX4otypit4+tIFVFNGB2FSp3Dl7NanXI47dtq33J6Q3eSz1u1h8tFZWExkntIohHJcxOgSNJd52FIEQJHt4c/Hjrnvb4kXr2wC5/tmzst2Lv5JzDYwtE8EkivCqX5ChihIAZSK7j8POuuW3btG85VcX2fYWsFpPLcgWtpKsFr/AGsMpo4/VkO4qxofYdZnbveIzcQz4++jyeSmxV9JcYbPWDOtjFMyywzRcQsnScFCTuqwA5a9uuk+fLn7UCyuG7pF8hktYJszhdtx2/fxK0bqlatbM/n6trMA0bxsPJWq0oBreENXZva2Iwd/lsnb5XLTXecdJ5ochOk3y7AsSsJTbSpk48+AA1Yh2tZJGXpzzrPGV/rCoSQe/wAvlP5NBeitlZR1GEhpRm8D79TIsQQQxFmiQBnpvK+NBw0FpH3cBw9us4V3qD9oPE3rt2tJ2n6q5NY0VMbnD+K2FQKVnJFwnhQrOGNPYw0FLDdzXcSor28M0YoOKsCB7tp0F2QY28vJZpYpI2lbcdhDDlw50PL36IO4m1xCYq7skuZY5LqeOYMyHaBGhUA7S3ifZoqzf4LuGXFWNjiO4GhtoLH5WS1jqikvIXlB3jm+4+YU8vl5V1izbPFb03x8O8Lc+pGLmu4pHe4tpyDEZFSREZa1ZEHlTdXiQNTr6/XXC9vb77ZUc/hO9czarHkxLdWyS9cxxqqKXUEAlVArTdwrreKxmM/v724wzSW72UTBnApcoxIIB4Ahl9upIgr23dy52SysDirN97iGNN0oCBubDe0gA1y20l+HXXt2nytzZfEWNzLZi1vI4oGeENa3KbSobzBVaNeDU1i/X1dP6nafhWyl72vmJ45p8nl7W4hbfE8yC42t7iJgfyas6JJwl79r5V2x1nMjLD3TZSuwZqXtpPDVmpxfajoSKc66z/BG/wCpr72zhc5i8jBJb3uLvbeqmURXsKGiturtmMZqCOFNY7ej2n6rp34rSXuo58TcvHi7qXM7CqyRNGwdZql445I3bb5Fo7fQBXXi/pts86vbPs6Y42C8HNdQ4efI5Wym+ckRNkl2rCUyAB1QRbeRK7TXw1jt19bz4b02m3yKQd343G4hJsdO1vmb2Fw9k/Hpmm0oxFfOiDgyEeGsdW0nOtauufKvbW8Rx9jPh416VsXmury5lDyzXDqUSFVBZivmNOFK0+nV6+yW4+TbXCt6c5CGeDum+yk8dtdPLb9GGegLR0ZGZV/WUNtBC67byeXPXa+2F+4u7KTuKzUJGLJGlElyEBYyxqsMcjDiBGEuZDt9nhXXLjOG/e5eWUa4B2qG3HjQA1pr7tkfDlE7a2upIKmTca16bSUHsPLWeG+XHykwViIk276b6GlT7zrXtIz60ShxsdwsNrBITcMFElTRSx8ErTh9OsXatescRYOzkumSaZYEKMQ6xtLRxyU0Ycz+trF32+FkhlmijtMBZYyD7uGONpnYEgyyzcSzAe6ij3DW/ZnHKxhcW0XbOSyRnjja1ntVhtTGxlk64kVyjjhtVVqQ31a3LwzYa/UjsBbK2tXhk69hmbGzzFqrsonSdofvfKvgwVuVfCp5au2YuOcMy/DbGH47maEHilEDlqcwADTXL+StXRSGPmn6avZylpf6rajBm+gAa6cM8o5u2k6fVNyIa/qyUY/4utYRRXG3UT1gmV2PBTEx3H6Bz1KQ24Ttf1DybKljbTdM0oZ+X2EFtWaWsbdmsaZhfQ/NvEs/cV7HZpwLJCKOR7Buamuk6fy5XuvxDniu1e08Kg+XhSS4UcZnO9/pqddddJHDbe3zVLMy2MUzXbcJun0RID+oTupTlz1rEzljPGGf57MgTUjYc+NfefdrNrprBDK36XGHwBBoLeO+hbx4LcmReP8A4usOgHNkn3hN4KUBoK8tUMfbim6uVjhj40G4+waqw/QkWs0aGlaCpJ/6cNRoaW6j68UYAJbi3s0VfaeHZvHhwqNTC5TQySPIFKDYR5SaGuoqplzb2kXzF28cG0hYQOLyGtQAg56m04XXbFZDk+8rUX1+s8imATuzK/xLtf4a/wA7hTXOVq83Jo9PfWC4wv4+MfAt5Y29gb6KxkZo+pcxyRxsUYK3TrG53LT9WutYCH316qd0d29wLdXt4+MtU2ILWzeSGBVQ7hudT1Hav6x+oDXOyW5b12xwuw5q5ls3kW8uyXhVpmlmlmRSnBeDsa8Gbaa6WR169cl3sOGe3yV5d3ELXXD+0SRgzSLGGqzhRViAR5gvGn0azrw7fZsuNY9Hdu4vBZ+ww3zLi8tVt36N5DJ94kkbgKqTLxFA1Np13nMeGyy4o9ZZO9s8i/b+TJvraFZJMffyBesEjAYo5FAzbTzAGrhB2PpkrLFJQHiI2PAgjxD6CVXkpURoPYQAf06YTKRMi8a06a7hzJ4/k0wZfHzE6kEulCabSKVr9emDImb+Lp1Rhy8PDWcLlPHcAxKT8RFSBqYV2GB4jw5j3amBg38X/a8OR7HxXcHSEkmFvljlJ8Le9HSb/wA5YtUeW7TE4+lY+rA3tilZT+c6gvwR38JpbZi7jI5dUrMPsYDQFbLKd4QgdDJWl0RyFzblK/XEdAzY/uvvqLYDgrPIn/4W76J+yaupkHsL6jLdTXVteYe5srqxl6FzF1IpdsgqCKjbyI0yq7lO6bYxmWGSaFuRNCtKe9CdUIedyFjlnX56aO7KFmQTMCw9pqSG1MpgJt47nF3MV5hpntZYjuiaM7wD9DbhqWLlVlvL4yM8yLI7Es7lWUkk1J8p1MD4t3QEtBz/AGX/ANJdFw/G8gYGqSIB7Qrfmauhh9SWxHDq0FakOrD9B1MmE8Zt2CiKaGu6p2uqsPoJIOqL1rfZuA/cXt3EK+VopnpT6FbVymFz+9ncwO2W/lmUVp8ykcvu/wBYjeGs3WVZtYmsu88natujgsSeRPy6xn2f6ox65X63XefWOk7t581HHn7KsjnDQB5WLs0M00ZqTVtquZVAJ58NX+n1/Cz7G8dRdwWMdvNGbW8PVQIE+YiKjzqxIbpAj4afCdc/6PXOeW/6rZlFtWs/yO3bQdelOVfLtrx+zXfb9XGLNt0PJ+J/DuNNtPdy2/p1Kq2n4T87F1ev8ruH+7b67fHZXy7tS+2OPIivuh+LT/I9Xo1b5bqfH0q8N373t26TOJnyTGU0nV6C12dKgrWuzfTzV/e9upwNl7b/ALobu6fnfkPlPwofI/ilPmut0Ur8n4bupu204/VXXbhj4XLT/l9/yyx/47+Kfhv4hN8lt+U3dbavVr0/vent5V/k0nhNvKHuv+4X9zO1fwH8S/Ed1x8r8zXf0eodu/f91s3btvS99dXfIyqP5rzbP6rca/Dv3eO7xprzOyf7zZJXd1to2bup1OYp06eP0+GpVgCPkvxP/i3U+T47Ol8H+H+t9NNejXxy47eeGw9if8selF+HfL/O0479tf8AE839LXo09Xj7ff5aHb/i3SX8Lp0//hdvL6uOuzhM/AdkfxPYvze/qVNerXdWvv1Wdshk3X2ybKU47d3Pn4aIU+4vxLb5q0pwrXlqVrUjz/N9YbqVr465u8GpPnfwmw6nwdW52U9tU311K6Kc/wAr8xFtr1tvCnKn8uiH3sXb0T8nTrV+96nxe73U1pYZLjr9Qb6c/Hn9WirVz1un5PioOnSu7lqAxhul0Iq9StT/AF3L37fD+loD8HU3DpUrwru+KmosKnqL1Pw6fb09/TanWr8fhSnHWa2885j5r5vx+a6I+a3bvj3f9p411wn6N/3iPa/4z8tk6U3fhV9u2+3pf0a7tv1a6XKTBav/AJvdH8109/HZtr+jhrnMtbYzwIYj+8/4fc/I/wC4eT5iu3Z8Xkru9/s0dOr3z+05+mvV+efpV6/TtttK03dWbq+/4ufu1dE7s55bz3H/AHN/vGny3zX94/P+I/3b6nzPUoadbo/2fqdb/wB5+vhrVx8ef0/t/wDK6e2Ocev/AOX9s/5KmC/v7+M//kXyv4dtm+T+Y2/iv9X5fmPk/wCx8ue3Wtfb5Z7f48ftzn/x/wCeTtD1+p97tptPLnTw10cEsnzOz7r6tQAr78a6nn6nRr/qKbqe+uqq1YdCn3fU61OPVru/LogtZ9b5iLq/7vu81Pb4btSqOwb9x/Z92sq+4zr7Z/mv63cfh5bPCmpQret/4J/yh7o/F6/I/IPsp8XzFR8rt/e+Y6dPfqLHhaD8Q6Y29OtBWu7nrI7T8Rrx2fVXQFLH5zcK0+qugcML8z1YvZuFforqKE4vpfjGf+Z3fNfiVxv6fV3fGeXT/Tq0X775v5Z+j83tpw6uzZz/AO182gU5OhvuPnen/VDZv28uoN/upSlfdqcgNL/dvefl69b/AOG6v5Nvl1UfI/xncfkvxKnh1fg/8zQWrf8Avr/rejt/7fp1/wDL46AhB85T+2fKV8ejvr+XTgWP7Fx9tDqCJvka+av/AE+nRUD/ACNfu67q8KU/RqKkh+d/1HzPu2dSn5eGnCcrJ/FfHfy/1vS/Tx1FdxfidfN8tT37q0/wNVFkdTaa9PqeHx7fr8dB/9k=\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'business-and-industry\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_2\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'199\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Business & industry\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-47\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'4\',
        \'source\' => \'node/4\',
        \'alias\' => \'business-industry\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'165\',
      \'uid\' => \'1\',
      \'title\' => \'FSA in Wales\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'78102601-5519-4092-b8d9-eff46f8a02d3\',
      \'nid\' => \'49\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1395146378\',
      \'changed\' => \'1395255102\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'d9eb598f-2831-4c0a-93f9-3712ff23a9f9\',
      \'revision_timestamp\' => \'1395255102\',
      \'revision_uid\' => \'1\',
      \'body\' => array(),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'wales\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'6\',
      \'current_revision_id\' => \'165\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Wales\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'48\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'FSA in Wales\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'53\',
        \'source\' => \'node/49\',
        \'alias\' => \'wales\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'73\',
      \'uid\' => \'1\',
      \'title\' => \'Search All\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1976b9ee-0912-42b5-97ef-677967a38fae\',
      \'nid\' => \'45\',
      \'type\' => \'landing_page\',
      \'language\' => \'und\',
      \'created\' => \'1394801456\',
      \'changed\' => \'1394801456\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'e3ab63c1-0bc1-4c39-8318-52119ec19140\',
      \'revision_timestamp\' => \'1394801456\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc faucibus nulla quis ligula consequat, vel vehicula lorem dapibus! Quisque facilisis vel tellus convallis placerat! Suspendisse at venenatis enim. Fusce ac massa porttitor, posuere sapien at, ornare diam. Integer mollis faucibus tempor. Etiam sit amet bibendum sem? Sed pellentesque magna vehicula ligula elementum placerat. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce a arcu lorem. Nam lorem tortor, luctus consequat ultrices semper, fringilla id augue. Suspendisse mollis quis nisl vel elementum. Ut tristique, lectus ac tincidunt mollis, massa diam dignissim massa, sed imperdiet nulla magna quis elit! Aenean id viverra enim. Curabitur dui ante, consectetur vel dui non, feugiat interdum lorem! Vivamus porttitor mattis lorem in rhoncus. Praesent dictum in urna et convallis. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin in leo nec enim volutpat scelerisque sit amet sed dolor. Fusce a elit sodales lacus condimentum placerat eget eget nisi. Quisque hendrerit est nec mattis vulputate. Suspendisse potenti. Ut aliquet elit eros. Sed dignissim diam ut vestibulum laoreet. Nulla varius tortor lacus, quis commodo eros dignissim vitae. Etiam ultrices in urna nec molestie. Mauris fringilla sodales hendrerit? Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aenean non arcu in massa convallis commodo at ac sapien. Integer at risus accumsan, dignissim neque nec, pellentesque arcu. Quisque eu fringilla mauris. Cras ac elementum libero, vel pellentesque tellus.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => \'<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc faucibus nulla quis ligula consequat, vel vehicula lorem dapibus! Quisque facilisis vel tellus convallis placerat! Suspendisse at venenatis enim. Fusce ac massa porttitor, posuere sapien at, ornare diam. Integer mollis faucibus tempor. Etiam sit amet bibendum sem? Sed pellentesque magna vehicula ligula elementum placerat. Interdum et malesuada fames ac ante ipsum primis in faucibus. Fusce a arcu lorem. Nam lorem tortor, luctus consequat ultrices semper, fringilla id augue. Suspendisse mollis quis nisl vel elementum. Ut tristique, lectus ac tincidunt mollis, massa diam dignissim massa, sed imperdiet nulla magna quis elit! Aenean id viverra enim. Curabitur dui ante, consectetur vel dui non, feugiat interdum lorem! Vivamus porttitor mattis lorem in rhoncus. Praesent dictum in urna et convallis. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin in leo nec enim volutpat scelerisque sit amet sed dolor. Fusce a elit sodales lacus condimentum placerat eget eget nisi. Quisque hendrerit est nec mattis vulputate. Suspendisse potenti. Ut aliquet elit eros. Sed dignissim diam ut vestibulum laoreet. Nulla varius tortor lacus, quis commodo eros dignissim vitae. Etiam ultrices in urna nec molestie. Mauris fringilla sodales hendrerit? Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Aenean non arcu in massa convallis commodo at ac sapien. Integer at risus accumsan, dignissim neque nec, pellentesque arcu. Quisque eu fringilla mauris. Cras ac elementum libero, vel pellentesque tellus.</p>\',
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(),
      \'field_banner_image\' => array(),
      \'field_subtitle\' => array(),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'search-all\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'1\',
      \'current_revision_id\' => \'73\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => NULL,
      \'path\' => array(
        \'pid\' => \'48\',
        \'source\' => \'node/45\',
        \'alias\' => \'search-all\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
  (object) array(
      \'vid\' => \'201\',
      \'uid\' => \'1\',
      \'title\' => \'Science and research\',
      \'log\' => \'\',
      \'status\' => \'1\',
      \'comment\' => \'1\',
      \'promote\' => \'0\',
      \'sticky\' => \'0\',
      \'vuuid\' => \'1cce433c-fb81-4059-a614-fd5ffcaf7102\',
      \'nid\' => \'6\',
      \'type\' => \'landing_page\',
      \'language\' => \'en\',
      \'created\' => \'1391442235\',
      \'changed\' => \'1395490504\',
      \'tnid\' => \'0\',
      \'translate\' => \'0\',
      \'uuid\' => \'f19767bf-03dc-4c10-880c-a0a4972a39a6\',
      \'revision_timestamp\' => \'1395490504\',
      \'revision_uid\' => \'1\',
      \'body\' => array(
        \'und\' => array(
          array(
            \'value\' => "<p>In this section you&#39;ll find details of the Agency&#39;s research projects and how to apply for research funding.</p>\\r\\n",
            \'summary\' => \'\',
            \'format\' => \'full_html\',
            \'safe_value\' => "<p>In this section you\'ll find details of the Agency\'s research projects and how to apply for research funding.</p>",
            \'safe_summary\' => \'\',
          ),
        ),
      ),
      \'field_summary\' => array(
        \'und\' => array(
          array(
            \'value\' => \'The Agency commissions scientific research to ensure that our advice is based on the best and most up-to-date science. We also work with a number of independent scientific committees.\',
            \'format\' => NULL,
            \'safe_value\' => \'The Agency commissions scientific research to ensure that our advice is based on the best and most up-to-date science. We also work with a number of independent scientific committees.\',
          ),
        ),
      ),
      \'field_banner_image\' => array(
        \'und\' => array(
          array(
            \'fid\' => NULL,
            \'uid\' => \'1\',
            \'filename\' => \'science.jpg\',
            \'uri\' => \'public://banner-image/science.jpg\',
            \'filemime\' => \'image/jpeg\',
            \'filesize\' => \'13439\',
            \'status\' => \'1\',
            \'timestamp\' => \'1394041140\',
            \'type\' => \'image\',
            \'uuid\' => \'10b809b5-7267-40c8-8d5b-ff3a8f90223b\',
            \'field_file_image_alt_text\' => array(
              \'und\' => array(
                array(
                  \'value\' => \'nice microscope\',
                  \'format\' => NULL,
                  \'safe_value\' => \'nice microscope\',
                ),
              ),
            ),
            \'field_file_image_title_text\' => array(),
            \'metatags\' => array(),
            \'rdf_mapping\' => array(),
            \'metadata\' => array(
              \'height\' => 164,
              \'width\' => 462,
            ),
            \'alt\' => \'nice microscope\',
            \'title\' => NULL,
            \'width\' => \'462\',
            \'height\' => \'164\',
            \'node_export_file_data\' => \'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\',
          ),
        ),
      ),
      \'field_subtitle\' => array(
        \'und\' => array(
          array(
            \'value\' => \'Subtitle here\',
            \'format\' => NULL,
            \'safe_value\' => \'Subtitle here\',
          ),
        ),
      ),
      \'field_path\' => array(
        \'und\' => array(
          array(
            \'human\' => NULL,
            \'machine\' => \'science-and-research\',
          ),
        ),
      ),
      \'field_popular_links\' => array(),
      \'field_block_reference\' => array(
        \'und\' => array(
          array(
            \'moddelta\' => \'views:news-block_4\',
          ),
        ),
      ),
      \'field_current_topics\' => array(),
      \'field_resources\' => array(),
      \'field_layout\' => array(),
      \'metatags\' => array(),
      \'rdf_mapping\' => array(
        \'rdftype\' => array(
          \'sioc:Item\',
          \'foaf:Document\',
        ),
        \'title\' => array(
          \'predicates\' => array(
            \'dc:title\',
          ),
        ),
        \'created\' => array(
          \'predicates\' => array(
            \'dc:date\',
            \'dc:created\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'changed\' => array(
          \'predicates\' => array(
            \'dc:modified\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
        \'body\' => array(
          \'predicates\' => array(
            \'content:encoded\',
          ),
        ),
        \'uid\' => array(
          \'predicates\' => array(
            \'sioc:has_creator\',
          ),
          \'type\' => \'rel\',
        ),
        \'name\' => array(
          \'predicates\' => array(
            \'foaf:name\',
          ),
        ),
        \'comment_count\' => array(
          \'predicates\' => array(
            \'sioc:num_replies\',
          ),
          \'datatype\' => \'xsd:integer\',
        ),
        \'last_activity\' => array(
          \'predicates\' => array(
            \'sioc:last_activity_date\',
          ),
          \'datatype\' => \'xsd:dateTime\',
          \'callback\' => \'date_iso8601\',
        ),
      ),
      \'name\' => \'Tharg\',
      \'picture\' => \'0\',
      \'data\' => \'b:0;\',
      \'num_revisions\' => \'3\',
      \'current_revision_id\' => \'201\',
      \'is_current\' => TRUE,
      \'is_pending\' => FALSE,
      \'revision_moderation\' => FALSE,
      \'menu\' => array(
        \'link_title\' => \'Science & research\',
        \'mlid\' => 0,
        \'plid\' => \'0\',
        \'menu_name\' => \'main-menu\',
        \'weight\' => \'-45\',
        \'options\' => array(),
        \'module\' => \'menu\',
        \'expanded\' => \'0\',
        \'hidden\' => \'0\',
        \'has_children\' => \'1\',
        \'customized\' => 0,
        \'parent_depth_limit\' => 8,
        \'description\' => \'\',
        \'enabled\' => 1,
      ),
      \'path\' => array(
        \'pid\' => \'2\',
        \'source\' => \'node/6\',
        \'alias\' => \'science\',
        \'language\' => \'und\',
      ),
      \'node_export_drupal_version\' => \'7\',
    ),
)',
);
  return $node_export;
}
