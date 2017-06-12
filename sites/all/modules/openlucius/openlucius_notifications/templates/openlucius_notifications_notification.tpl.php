<?php
/**
 * @file
 * The HTML for the notification email.
 */
?>
<?php if (isset($vars['before'])): ?>
  <span style="font-size: 10px;color: #7c7c7c;"><?php print $vars['before']; ?></span>
<?php endif; ?>
<html>
<head>
  <title>
    <?php if (isset($vars['title'])): ?>
      <?php print $vars['title']; ?>
    <?php endif; ?>
  </title>
</head>
<body style="background-color: #f2f2f2;" background="#f2f2f2" width="100%">
<div style="background-color: #f2f2f2; padding: 50px 0 50px 50px;" background="#f2f2f2" width="100%">
  <table cellpadding="0" cellspacing="0" style="margin:auto; max-width:600px;">
    <tbody>
    <tr>
      <td style="font-family: Roboto, sans-serif;">
        <?php if (isset($vars['title'])): ?>
          <h2 style="color: #222; font-weight: lighter; line-height: 1.1; font-size: 32px;">
            <?php print $vars['title']; ?>
          </h2>
        <?php endif; ?>
      </td>
    </tr>
    <tr style="border-top: 1px solid ">
      <td>
        <table cellpadding="0" cellspacing="0" style="background-color: #FFFFFF; border-left: 1px solid #e8e8e8;" background="#FFFFFF">
          <tbody background="#FFFFFF" style="background-color: #fff;">
          <!-- table top -->
          <tr>
            <td></td>
          </tr>
          <tr>
            <td>
              <!-- body -->
              <table cellpadding="0" cellspacing="0" style="max-width: 100%;">
                <tbody>
                <tr>
                  <td colspan="5" height="24" style="border-top: 1px solid #e8e8e8;"></td>
                  <td width="1" style="background-color: #d9d9d9;"></td>
                  <td width="1" style="background-color: #e7e7e6;"></td>
                  <td width="1" style="background-color: #ebeae7;"></td>
                  <td width="1" style="background-color: #f3f0ea;"></td>
                  <td width="1" style="background-color: #f9f4ed;"></td>
                </tr>
                <tr>
                  <td width="14"></td>
                  <td valign="top">
                  </td>
                  <td width="10"></td>
                  <td valign="top" style="color: #222; font-family: Roboto, sans-serif; line-height: 1.428571429; font-size: 15px;">
                    <?php if (isset($vars['mail_header'])): ?>
                      <span style="font-style: italic; font-weight: 400; color: #777; font-size: 12px;">
                                <?php print $vars['mail_header']; ?>
                              </span>
                      <br/><br/>
                    <?php endif; ?>
                    <?php print $vars['body']; ?>
                    <br/><br/>
                    <?php if (isset($vars['read_more'])): ?>
                      <?php print $vars['read_more']; ?>
                      <br/><br/>
                    <?php endif; ?>

                    <?php if (isset($vars['info'])): ?>
                      <span style="font-style: italic;">
                                <?php print $vars['info']; ?>
                              </span>
                    <?php endif; ?>
                    <br/><br/>
                            <span style="font-style: italic; font-weight: 400; color: #777; font-size: 12px;">
                              <?php print t('Powered by') . ' '; ?>
                              <a href="http://www.openlucius.com">OpenLucius</a> | <?php print l(t('Help'), 'http://help.openlucius.com/content/please-choose-manual', array('attributes' => array('target' => '_blank'))); ?>
                            </span>
                  </td>
                  <td width="14"></td>
                  <td width="1" style="background-color: #d9d9d9;"></td>
                  <td width="1" style="background-color: #e7e7e6;"></td>
                  <td width="1" style="background-color: #ebeae7;"></td>
                  <td width="1" style="background-color: #f3f0ea;"></td>
                  <td width="1" style="background-color: #f9f4ed;"></td>
                </tr>
                <tr>
                  <td colspan="5" height="24"></td>
                  <td width="1" style="background-color: #d9d9d9;"></td>
                  <td width="1" style="background-color: #e7e7e6;"></td>
                  <td width="1" style="background-color: #ebeae7;"></td>
                  <td width="1" style="background-color: #f3f0ea;"></td>
                  <td width="1" style="background-color: #f9f4ed;"></td>
                </tr>
                <!-- bottom shadow -->
                <tr>
                  <td colspan="10" height="1" style="background-color: #d9d9d9;"></td>
                </tr>
                <tr>
                  <td colspan="10" height="1" style="background-color: #e7e7e6;"></td>
                </tr>
                <tr>
                  <td colspan="10" height="1" style="background-color: #ebeae7;"></td>
                </tr>
                <tr>
                  <td colspan="10" height="1" style="background-color: #f3f0ea;"></td>
                </tr>
                <tr>
                  <td colspan="10" height="1" style="background-color: #f9f4ed;"></td>
                </tr>
                </tbody>
              </table>
            </td>
          </tr>
          </tbody>
        </table>
      </td>
    </tr>
    </tbody>
  </table>
</div>
</body>
</html>
<?php
// Allow other modules to place content after the html.
if (isset($vars['after'])) {
  print $vars['after'];
}
?>
